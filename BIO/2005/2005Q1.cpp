#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char const *argv[])
{
	std::string n;
	std::cin>>n;
	std::string dec = n.substr(2);
	int power = dec.size();
	int numerator = std::stoi(dec);
	int denominator = std::pow(10,power);
	while (true){
		if (numerator%5==0&&denominator%5==0){
			numerator/=5;
			denominator/=5;
		} else if (numerator%2==0&&denominator%2==0){
			numerator/=2;
			denominator/=2;
		} else {
			break;
		}
	}
	std::cout<<numerator<<" / "<<denominator<<std::endl;
	return 0;
}