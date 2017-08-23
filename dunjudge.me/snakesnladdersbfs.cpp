#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
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
		nodes.pop();
		for (long i : adjlist[current]){
			if (distances[i]==-1){
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

std::vector<std::vector<long> > adjlistcreator(std::vector<long> mapping){
	std::vector<std::vector<long> > adjlist(mapping.size());
	for (long i = 0; i<mapping.size(); i++){
		for (long j = i+1; j<mapping.size()&&j<i+7; j++){
			adjlist[i].push_back(mapping[j]);
		}
	}
	return adjlist;
}

int main(int argc, char const *argv[])
{
	long n,s;
	std::cin>>n>>s;
	std::vector<long> mapping(n);
	std::map<long, long> map;
	long go1, go2;
	for (long i = 0; i<s; i++){
		std::cin>>go1>>go2;
		map[go1-1] = go2-1;
	}
	long mapval;
	for (long j = 0; j<n; j++){
		if (map.find(j)!=map.end()){
			mapval = map[j];
			while (map.find(mapval)!=map.end()){
				mapval = map[mapval];
			}
			mapping[j] = mapval;
		} else {
			mapping[j] = j;
		}
	}
	map.clear();
	std::vector<std::vector<long> > adjlist = adjlistcreator(mapping);

	long dist = bfs(adjlist,0,n-1);
	std::cout<<dist<<std::endl;
	return 0;
}