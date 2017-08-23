#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
	double m,c;
	std::cin>>m>>c;
	double ans = -1*c/m;
	std::cout<<std::fixed<<std::setprecision(1)<<ans<<std::endl;
	return 0;
}