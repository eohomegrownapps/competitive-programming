#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	long long n;
	std::cin>>n;
	std::vector<long long> v;
	long long temp;
	for (long long i = 0; i<n; i++){
		std::cin>>temp;
		if (temp<366){
			v.push_back(temp);
		}
	}
	std::sort(v.begin(), v.end());
	for (long long j = 0; j<v.size(); j++){
		std::cout<<v[j];
		if (j==v.size()-1){
			std::cout<<std::endl;
		} else {
			std::cout<<" ";
		}
	}
	return 0;
}