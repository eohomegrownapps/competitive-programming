#include <string>
#include <iostream>
const int PRIME = 16777213;
int calculateHash(std::string search){
	int hash = 0;
	int hashcount = 1;
	for (int i = search.length()-1; i>=0; i--){
		int x = search[i];
		hash += (hashcount*x)%PRIME;
		hash = hash%PRIME;
		hashcount = hashcount*128;
		hashcount = hashcount%PRIME;
	}
	return hash;
}

//int rollingHash

int firstString(std::string search, std::string str){
	if (search.length()>str.length()){
		return -1;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	std::string search;
	std::cin>>search;
	std::cout<<calculateHash(search)<<std::endl;
	return 0;
}