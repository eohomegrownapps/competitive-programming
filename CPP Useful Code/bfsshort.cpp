#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

long bfs(std::vector<std::vector<long> > adjlist, long node, long destnode){
	std::vector<long> distances;
	for (long i = 0; i<adjlist.size(); i++){
		distances.push_back(-1);
	}
	std::queue<long> nodes;
	nodes.push(node);
	distances[node] = 0;
	long current;
	while (nodes.size()!=0){
		current = nodes.front();
		std::cout<<"current "<<current<<std::endl;
		nodes.pop();
		for (long i : adjlist[current]){
			std::cout<<"check "<<i<<std::endl;
			if (distances[i]==-1){
				std::cout<<i<<std::endl;
				distances[i] = distances[current]+1;
				nodes.push(i);
			}
			if (i==destnode){
				return distances[i];
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	//gives you adjacency list - adjlist. {0:{1,5},1:{12,5} etc.} from list of node pairs.
	long n,e;
	std::cin>>n>>e;
	std::vector<std::vector<long> > adjlist(n);
	long nodea, nodeb;
	for (long i = 0; i<e; i++){
		std::cin>>nodea>>nodeb;
		adjlist[nodea].push_back(nodeb);
		adjlist[nodeb].push_back(nodea);
	}
	long distance = bfs(adjlist,0,n-1);
	std::cout<<distance<<std::endl;
	return 0;
}