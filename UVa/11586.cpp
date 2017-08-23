#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	std::string x = "";
	std::getline(std::cin, x);
	for (int i = 0; i<n; i++){
		std::getline(std::cin, x);
		int male = 0;
		int female = 0;
		if (x.size()==2){
			std::cout<<"NO LOOP"<<std::endl;
		} else {
			for (int i = 0; i<x.size(); i++){
				if (x[i]=='M'){
					male++;
				} else {
					if (x[i]=='F'){
						female++;
					}
				}
			}
			if (male!=female){
				std::cout<<"NO ";
			}
			std::cout<<"LOOP"<<std::endl;
		}
	}
	return 0;
}