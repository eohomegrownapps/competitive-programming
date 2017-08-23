#include <iostream>
#include <algorithm>
#include <vector>
//shortest distance from x to y
long bfs(std::vector<std::vector<long> > adjlist, long node, long destnode){
	std::vector<long> unvisited;
	for (long i = 0; i<adjlist.size(); i++){
		unvisited.push_back(1);
	}
	std::vector<long> nodesavailable;
	long currentdistance = 0;
	long i, j;
	nodesavailable.push_back(node);
	std::vector<long> newnodesavailable;
	while (true){
		std::cout<<"start"<<std::endl;
		for (i = 0; i<nodesavailable.size(); i++){
			std::cout<<nodesavailable[i]<<std::endl;
			std::cout<<"nodes from here"<<std::endl;
			for (j = 0; j<adjlist[nodesavailable[i]].size(); j++){
				long temp = adjlist[nodesavailable[i]][j];
				if (unvisited[temp]==1){
					std::cout<<"checking"<<temp<<std::endl;
					unvisited[temp] = 0;
					if (temp == destnode){
						return currentdistance+1;
					}
					newnodesavailable.push_back(temp);
					std::cout<<"new "<<temp<<std::endl;
				}
			}
		}
		nodesavailable = newnodesavailable;
		newnodesavailable.clear();
		currentdistance++;
		if (nodesavailable.size()==0){
			return -1;
		}
	}
}