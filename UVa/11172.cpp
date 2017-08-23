#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	long a,b;
	for (int i = 0; i<n; i++){
		std::cin>>a>>b;
		if (a>b){
			std::cout<<">"<<std::endl;
		} else if (a<b){
			std::cout<<"<"<<std::endl;
		} else {
			std::cout<<"="<<std::endl;
		}
	}
	return 0;
}