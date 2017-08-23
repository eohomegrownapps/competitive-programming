#include <iostream>
int main(int argc, char const *argv[])
{	
	int x;
	std::cin>>x;
	int arr[4] = {10,670,55252,4816030};
	std::cout<<arr[x/2-1]<<std::endl;
	return 0;
}