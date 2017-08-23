#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	char first;
	char second;
	for (int i = 0; i<n; i++){
		if (i%2==0){
			first = 'o';
			second = 'x';
		} else {
			first = 'x';
			second = 'o';
		}
		for (int j = 0; j<n; j++){
			if (j%2==0){
				std::cout<<first;
			} else {
				std::cout<<second;
			}
		}
		std::cout<<std::endl;
	}
	return 0;
}