#include <iostream>

int main(int argc, char const *argv[])
{
	int n,e;
	std::cin>>n>>e;
	int adjmatrix[n][n];
	int j,k;
	for (j = 0; j<n; j++){
		for (k = 0; k<n; k++){
			adjmatrix[j][k] = 0;
		}
	}
	int nodea, nodeb;
	for (int i = 0; i<e; i++){
		std::cin>>nodea>>nodeb;
		nodea--;
		nodeb--;
		adjmatrix[nodea][nodeb] = 1;
		adjmatrix[nodeb][nodea] = 1;
	}
	for (j = 0; j<n; j++){
		for (k = 0; k<n; k++){
			std::cout<<adjmatrix[j][k];
		}
		std::cout<<std::endl;
	}
	return 0;
}