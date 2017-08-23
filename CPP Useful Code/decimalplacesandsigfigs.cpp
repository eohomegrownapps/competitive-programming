#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
	double n = 12.39557932;
	//to 2sf
	std::cout<<std::setprecision(2)<<n<<std::endl;

	//to 2dp
	std::cout<<std::fixed<<std::setprecision(2)<<n<<std::endl;
	return 0;
}