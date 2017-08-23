#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::string line;
	std::cin>>line;
	int n;
	try {
		n = std::stoi(line);
		std::cout<<n*2<<std::endl;
		return 0;
	} catch(...){
		std::transform(line.begin(), line.end(), line.begin(), toupper);
		std::cout<<line<<std::endl;
		return 0;
	}
	return 0;
}