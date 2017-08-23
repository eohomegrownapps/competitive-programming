#include <iostream>

int main(int argc, char const *argv[])
{
	long n,m;
	std::cin>>n>>m;
	while (n!=0||m!=0){
		if (n==0||m==0){
			int temp;
			for (int i = 0; i<n; i++){
				std::cin>>temp;
			}
			for (int i = 0; i<m; i++){
				std::cin>>temp;
			}
			std::cout<<0<<std::endl;
		} else {
			long narr[1000000];
			long temp;
			for (long i = 0; i<n; i++){
				std::cin>>temp;
				narr[i] = temp;
			}
			long same = 0;
			long pointer = 0;
			for (long i = 0; i<m; i++){
				std::cin>>temp;
				if (pointer<n){
					if (temp>narr[pointer]){
						while (temp>narr[pointer]){
							pointer++;
						}
					}
					if(temp==narr[pointer]){
						same++;
						pointer++;
					} else if (temp>narr[pointer]){
						pointer++;
					}
				}
			}
			std::cout<<same<<std::endl;
		}
		std::cin>>n>>m;
	}
	return 0;
}