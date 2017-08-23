#include <iostream>
#include <vector>

bool reversesort (int i,int j) { return (i>j); }

int main(int argc, char const *argv[])
{
	int n,guards,box,max;
	std::cin>>n>>guards>>box;
	std::vector<int> array[500];
	int temp;
	int temppotato;
	for (int a = 0; a<n; a++){
		std::cin>>temppotato>>temp;
		array[temp].push_back(temppotato);
	}
	for (int b = 0; b<n; b++){
		std::sort(array[b].begin(), array[b].end(),reversesort);
	}
	
	return 0;
}