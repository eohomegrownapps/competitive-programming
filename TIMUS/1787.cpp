#include <iostream>
int main(int argc, char const *argv[])
{
	int k, n, b, cars;
	cars = 0;
	std::cin>>k>>n;
	//std::cout<<b<<std::endl;
	for (int i = 0; i<n; i++){
		std::cin>>b;
		//std::cout<<b<<std::endl;
		cars += b;
		cars -= k;
		if (cars<0){
			cars = 0;
		}
	}
	if (cars<1){
		std::cout<<"0"<<std::endl;
	}
	else{
		std::cout<<cars<<std::endl;
	}
	return 0;
}