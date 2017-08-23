#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
int main(int argc, char const *argv[])
{
	long double n;
	std::vector<long double> arr;
	while (std::cin >> n){
	   	arr.push_back(n);
	}
	std::reverse(arr.begin(), arr.end());
	std::cout.precision(4);
	for (int i = 0; i<arr.size(); i++){
		std::cout<<std::fixed<<std::sqrt(arr[i])<<std::endl;
	}
	return 0;
}