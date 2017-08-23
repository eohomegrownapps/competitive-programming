#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	std::string s;
	char l;
	char num[] = {'2','4','6','8','0'};
	bool even;
	for (int i = 0; i<n; i++){
		even = false;
		std::cin>>s;
		l = s.at(s.length()-1);
		for (int i = 0; i<5; i++){
			if (l==num[i]){
				std::cout<<"even"<<std::endl;
				even = true;
			}
		}
		if (even==false){
			std::cout<<"odd"<<std::endl;
		}
	}
	return 0;
}