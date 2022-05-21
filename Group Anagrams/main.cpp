/*By Cebastian Santiago
* Leetcode 242
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

//helper function 
std::vector<std::vector<std::string>> groupAnagramshelper(std::map<std::string,std::vector<std::string>> maps){
	//variables
	std::vector<std::vector<std::string>> anagrams;

	for (auto& i : maps){
		anagrams.push_back(i.second);

	}

	return anagrams;
}




std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
	//variables
	std::map<std::string, std::vector<std::string>> hash;
	std::string sort = "";
	
	//for loop to store the strings in the hash function
	for (size_t i = 0; i < strs.size(); i++) {
		//get the current string and sort it
		sort = strs[i];
		std::sort(sort.begin(), sort.end());


		//check if weve havent seen this string
		if (hash.find(sort) == hash.end()) {
			hash[sort].push_back(strs[i]);
		
		}

		//if weve already seen this string push it back in the
		//same vector
		else {
			hash[sort].push_back(strs[i]);
		}
	
	}

	return groupAnagramshelper(hash);
}

int main() {
	std::vector<std::string> anagrams = { "eat", "tea", "tan", "ate", "nat", "bat" };
	std::vector<std::vector<std::string>> ana;
	
	ana = groupAnagrams(anagrams);

	//cout what we got
	for (size_t i = 0; i < ana.size(); i++) {
		for (size_t j = 0; j < ana[i].size(); j++){
			std::cout << ana[i][j] << std::endl;
		}
	}


	return 0;
}