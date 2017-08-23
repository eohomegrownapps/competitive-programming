#include <iostream>
#include <string>
long factorial(int num, int k, int stop){
	if (num==stop){
		return stop;
	}
	else {
		return factorial(num-k, k, stop)*num;
	}

}

int main(int argc, char const *argv[])
{
	int x;
	std::string y;
	std::cin>>x>>y;
	int mod;
	int len = y.length();
	if (x%len==0){
		mod=len;
	}
	else {
		mod=x%len;
	}
	std::cout<<factorial(x,len,mod)<<std::endl;
	return 0;
}