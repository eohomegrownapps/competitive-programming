#include <string>
#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
	std::string binary;
	std::cin>>binary;
	long bin = 0;
	long count = std::pow(2,binary.length()-1);
	for (int i = 0; i<binary.length(); i++){
		if (binary.at(i)=='1'){
			bin+=count;
		}
		count/=2;
	}
	std::cout<<bin<<std::endl;
	return 0;
}