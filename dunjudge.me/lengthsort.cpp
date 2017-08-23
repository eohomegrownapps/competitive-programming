#include <iostream>
#include <algorithm>
#include <vector>

bool strsort(std::string a, std::string b){
	if (a.length()>b.length()){
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	std::string in;
	std::cin>>n;
	std::vector<std::string> str;
	for (int i = 0; i<n; i++){
		std::cin>>in;
		str.push_back(in);
	}
	std::stable_sort(str.begin(), str.end(), strsort);
	for (int j = 0; j<n; j++){
		std::cout<<str[j]<<std::endl;
	}
	return 0;
}