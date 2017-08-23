#include <iostream>

int main(int argc, char const *argv[])
{
	int h,w;
	std::cin>>h>>w;
	int sum = 0;
	char temp;
	for (int i = 0; i<h*w; i++){
		std::cin>>temp;
		if (temp == '#'){
			sum += 1;
		}
	}
	std::cout<<sum<<std::endl;
	return 0;
}