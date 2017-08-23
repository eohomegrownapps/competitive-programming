#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::string a,b;
	std::getline(std::cin,a);
	std::getline(std::cin,b);
	std::vector<char> as,bs;
	for (int i = 0; i<a.size(); i++){
		if (std::isalpha(a[i])){
			as.push_back(std::tolower(a[i]));
		}
	}
	for (int i = 0; i<b.size(); i++){
		if (std::isalpha(b[i])){
			bs.push_back(std::tolower(b[i]));
		}
	}
	if (as.size()!=bs.size()){
		std::cout<<"NO"<<std::endl;
		return 0;
	}
	std::sort(as.begin(), as.end());
	std::sort(bs.begin(), bs.end());
	for (int i = 0; i<as.size(); i++){
		if (as[i]!=bs[i]){
			std::cout<<"NO"<<std::endl;
			return 0;
		}
	}
	std::cout<<"YES"<<std::endl;
	return 0;
}