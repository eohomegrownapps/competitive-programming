#include <iostream>
int main(int argc, char const *argv[])
{
	int a,b;
	std::cin>>a>>b;
	if ((a%2==0)||(b%2==1)){
		std::cout<<"yes"<<std::endl;
	}
	else{
		std::cout<<"no"<<std::endl;
	}
	return 0;
}