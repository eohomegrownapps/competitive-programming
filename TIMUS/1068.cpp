#include <iostream>
#include <cmath>
int main(int argc, char const *argv[])
{
	long a;
	std::cin>>a;
	long ans;
	if (a<1){
		ans = labs(a);
		ans = (((ans*(ans+1))/2)*-1)+1;
	} else {
		ans = a;
		ans = (ans*(ans+1))/2;
	}
	std::cout<<ans<<std::endl;
	return 0;
}