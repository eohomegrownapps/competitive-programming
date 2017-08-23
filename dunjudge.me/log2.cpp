#include <iostream>

long dividebytwo(long n, long count = 0){
	if (n<2){
		return count;
	}
	n = n/2;
	count += 1;
	return dividebytwo(n,count);
}

int main(int argc, char const *argv[])
{
	long num;
	std::cin>>num;
	std::cout<<dividebytwo(num)<<std::endl;
	return 0;
}