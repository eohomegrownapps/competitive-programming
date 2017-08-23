#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	//gives you adjacency list - adjlist. {0:{1,5},1:{12,5} etc.} from list of node pairs.
	int n,e;
	std::cin>>n>>e;
	std::vector<std::vector<int> > adjlist(n);
	int nodea, nodeb;
	for (int i = 0; i<e; i++){
		std::cin>>nodea>>nodeb;
		nodea--;
		nodeb--;
		adjlist[nodea].push_back(nodeb);
		adjlist[nodeb].push_back(nodea);
	}

	int j,k;
	for (j = 0; j<n; j++){
		for (k = 0; k<adjlist[j].size(); k++){
			std::cout<<adjlist[j][k]+1;
			if (k!=adjlist[j].size()-1){
				std::cout<<" ";
			}
		}
		std::cout<<std::endl;
	}
	return 0;
}