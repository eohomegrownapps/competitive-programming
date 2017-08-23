#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string x = "";
	std::getline(std::cin, x);
	if (x=="Hello World"){
		std::cout<<"OK"<<std::endl;
	} else {
		std::cout<<"Wrong Answer"<<std::endl;
	}
	return 0;
}