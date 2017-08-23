#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main(int argc, char const *argv[])
{
	std::map<std::string,std::string> strs;
	std::string x;
	std::cin>>x;
	while (x!="#"){
		std::string temp = x;
		std::transform(x.begin(), x.end(), x.begin(), ::tolower);
		std::sort(x.begin(), x.end());
		//std::cout<<x<<std::endl;
		int y = strs.count(x);
		if(y==0 || x.size()==1){
		    strs.insert(std::make_pair(x,temp));
		} else {
			strs[x]="";
		}
		std::cin>>x;
	}
	std::vector<std::string> strings;
	for (auto x : strs){
		if (x.second!=""){
			strings.push_back(x.second);
		}
	}
	std::sort(strings.begin(), strings.end());
	for (auto y : strings){
		std::cout<<y<<std::endl;
	}
	return 0;
}