#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	std::vector<int> gifts;
	gifts.resize(n+1);
	int temp;
	for (int i = 1; i<n+1; i++){
		std::cin>>temp;
		gifts[temp]=i;
	}
	for (int j = 1; j<n+1; j++){
		std::cout<<gifts[j]<<std::endl;
	}
	return 0;
}