#include <iostream>
#include <algorithm>
#include <vector>

bool descending(int i, int j){
	return i>j;
}

long overtimepay(std::vector<int> d, std::vector<int> n, int x){
	std::sort(d.begin(), d.end());
	std::sort(n.begin(), n.end(), descending);
	int sum = 0;
	for (int i = 0; i<d.size(); i++){
		if (d[i]+n[i]>x){
			sum+=d[i]+n[i]-x;
		}
	}
	return sum*100;
}

int main(int argc, char const *argv[])
{
	std::vector<int> d;
	std::vector<int> ni;
	int n,x;
	std::cin>>n;
	int temp;
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		d.push_back(temp);
	}
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		ni.push_back(temp);
	}
	std::cin>>x;
	std::cout<<overtimepay(d,ni,x)<<std::endl;
	return 0;
}