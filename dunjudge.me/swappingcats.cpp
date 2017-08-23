#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::vector<int> catnos;
	int n;
	std::cin>>n;
	for (int i = 0; i<n; i++){
		catnos.push_back(i);
	}
	int a,b,temp;
	int x;
	std::cin>>x;
	for (int i = 0; i<x; i++){
		std::cin>>a>>b;
		temp = catnos[b];
		catnos[b] = catnos[a];
		catnos[a] = temp;
	}
	for (int j = 0; j<n; j++){
		std::cout<<catnos[j]<<std::endl;
	}
	return 0;
}