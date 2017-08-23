#include <iostream>
#include <vector>
#include <algorithm>

bool sort(int a, int b){
	return a>b;
}

int main(int argc, char const *argv[])
{
	int n, sum, temp, i;
	sum = 0;
	std::cin>>n;
	for (i = 0; i<n; i++){
		std::cin>>temp;
		sum += temp;
	}
	std::vector<int> v;
	for (i = 0; i<n; i++){
		std::cin>>temp;
		if (temp!=0){
			v.push_back(temp);
		}
	}
	std::sort(v.begin(), v.end(),sort);
	for (i = 0; i<v.size(); i++){
		sum += v[i]*i;
	}
	std::cout<<sum<<std::endl;
	return 0;
}