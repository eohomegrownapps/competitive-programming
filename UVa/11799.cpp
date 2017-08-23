#include <iostream>

int main(int argc, char const *argv[])
{
	int t;
	std::cin>>t;
	for (int i = 1; i<t+1; i++){
		int n;
		std::cin>>n;
		int max = -1;
		int temp;
		for (int j = 0; j<n; j++){
			std::cin>>temp;
			if (temp>max){
				max=temp;
			}
		}
		std::cout<<"Case "<<i<<": "<<max<<std::endl;
	}
	return 0;
}