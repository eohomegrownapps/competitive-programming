#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string x = "";
	int num;
	std::cin>>num;
	std::getline(std::cin,x);
	std::getline(std::cin,x);
	int j;
	for (int i = 0; i<num; i++){
		for (j=0; j<i; j++){
			std::cout<<" ";
		}
		std::cout<<x<<std::endl;
	}
	return 0;
}