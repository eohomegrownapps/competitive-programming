#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string x = "";
	int num;
	std::cin>>num;
	std::getline(std::cin,x);
	std::getline(std::cin,x);
	for (int i = 0; i<num; i++){
		std::cout<<x<<std::endl;
	}
	return 0;
}