#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	for (int i = 0; i<n; i++){
		unsigned long long f;
		std::cin>>f;
		if (f>=4294967291){
			std::cout<<0<<std::endl;
		} else {
			unsigned long long ans = 1;
			for (unsigned long long j = 1; j<=f; j++){
				ans*=j;
				if (ans>4294967291){
					ans%=4294967291;
				}
			}
			std::cout<<ans<<std::endl;
		}
	}
	return 0;
}