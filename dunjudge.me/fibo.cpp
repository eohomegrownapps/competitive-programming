#include <iostream>
#include <vector>

int fibo(int n, int m){
	std::vector<int> v;
	v.push_back(0%m);
	v.push_back(1%m);
	while (v.size()<n+1){
		v.push_back((v[v.size()-1]+v[v.size()-2])%m);
	}
	return v[n];
}

int main(int argc, char const *argv[])
{
	int n,m;
	std::cin>>n>>m;
	std::cout<<fibo(n,m)<<std::endl;
	return 0;
}