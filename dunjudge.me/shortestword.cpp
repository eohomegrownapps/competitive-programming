#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	int n;
	std::string s;
	std::string shortest;
	std::cin>>n;
	std::cin>>shortest;
	for (int i = 1; i<n; i++){
		std::cin>>s;
		if (s.size()<shortest.size()){
			shortest = s;
		}
	}
	std::cout<<shortest<<std::endl;
	return 0;
}