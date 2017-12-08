#include <iostream>

int main(int argc, char const *argv[])
{
	long n,k;
	std::cin>>n>>k;
	long gifts = 0;
	long oldtime, newtime;
	std::cin>>oldtime;
	for (long i = 1; i<n; i++){
		std::cin>>newtime;
		if ((oldtime-newtime)>=k){
			gifts++;
		}
		oldtime = newtime;
	}
	std::cout<<gifts<<std::endl;
	return 0;
}