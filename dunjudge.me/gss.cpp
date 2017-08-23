#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	std::vector<int> v;
	int temp;
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		v.push_back(temp);
	}
	std::sort(v.begin(), v.end());
	int sum = 0;
	for (int j = 0; j<v.size(); j++){
		if (j%4!=3|v.size()<4){
			sum += v[v.size()-1-j];
		}
	}
	std::cout<<sum<<std::endl;
	return 0;
}