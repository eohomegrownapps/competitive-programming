#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	int n,m;
	std::cin>>n>>m;
	int fence = 0;
	std::string inst;
	for (int i = 0; i<m; i++){
		std::cin>>inst;
		if (inst == "LAND") fence += 1;
		if (inst == "LEAVE") fence -= 1;
		if (inst == "EVACUATE") fence = 0;
		if (fence<0||fence>n){
			std::cout<<"PLAN REJECTED"<<std::endl;
			return 0;
		}
	}
	std::cout<<"PLAN ACCEPTED"<<std::endl;
	return 0;
}