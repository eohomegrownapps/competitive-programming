#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	int n, m;
	std::cin>>n>>m;
	std::vector<int> v;
	int temp;
	for (int i = 0; i<m; i++){
		std::cin>>temp;
		v.push_back(temp);
	}
	std::sort(v.begin(), v.end());
	int total = 0;
	int j;
	for (j = 0; j<m; j++){
		total+=v[j];
		if (total>n){
			std::cout<<j<<std::endl;
			return 0;
		}
	}
	std::cout<<m<<std::endl;
	return 0;
}