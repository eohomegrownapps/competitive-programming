#include <iostream>

int main(int argc, char const *argv[])
{
	long n;
	std::cin>>n;
	long max = 0;
	long current = 0;
	long temp;
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		if (temp==-1){
			if (max<current){
				max=current;
			}
			current=0;
		} else {
			current+=temp;
		}
	}
	if (max<current){
		max=current;
	}
	std::cout<<max<<std::endl;
	return 0;
}