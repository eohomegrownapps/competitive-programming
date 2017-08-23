#include <iostream>

int main(int argc, char const *argv[])
{
	int len, time;
	std::cin>>len>>time;
	for (int i = 1; i<time; i++){
		if (len==1){
			len=-1;
			break;
		} else if (len%2==0){
			len = len/2;
		} else {
			len = len*3+1;
		}
	}
	std::cout<<len<<std::endl;
	return 0;
}