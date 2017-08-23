#include <iostream>
int main(int argc, char const *argv[])
{
	int n,m;
	std::cin>>n>>m;
	if (n%m==0){
		std::cout<<"Yes"<<std::endl;
	} else {
		std::cout<<"No"<<std::endl;
	}
	return 0;
}