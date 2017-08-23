#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>

long bfs(std::map<long, std::vector<long> > adjlist, long node, long destnode){
	std::map<long, long> distances;
	for(auto iterator = adjlist.begin(); iterator != adjlist.end(); iterator++) {
		distances[iterator->first]=-1;
	}
	std::queue<long> nodes;
	nodes.push(node);
	distances[node] = 0;
	long current;
	while (nodes.size()!=0){
		current = nodes.front();
		//std::cout<<"current "<<current<<std::endl;
		nodes.pop();
		for (long i : adjlist[current]){
			//std::cout<<"check "<<i<<std::endl;
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

std::vector<bool> eratosthenes(long limit){
	std::vector<bool> v(limit+1);
	std::fill(v.begin(), v.end(),true);
	v[0] = false;
	v[1] = false;
	v[2] = true;
	for (long i = 2; i<limit+1; i++){
		if (v[i]==true){
			for (long j = i*2; j<limit+1; j+=i){
				if (v[j] == true){
					v[j] = false;
				}
			}
		}
	}
	return v;
}

std::map<long, std::vector<long> > makeadjlist(long limit){
	std::vector<bool> erato = eratosthenes(limit);
	std::vector<long> temp;
	std::map<long, std::vector<long> > adjlist;
	for (long i = 2; i<limit+1; i++){
		if (erato[i]==true){
			long count = 0;
			long power = pow(2,count)+i;
			while (power<limit+1){
				if (erato[power]==true){
					if (adjlist.find(power)==adjlist.end()){
						adjlist[power] = temp;
					}
					adjlist[power].push_back(i);
					if (adjlist.find(i)==adjlist.end()){
						adjlist[i] = temp;
					}
					adjlist[i].push_back(power);
				}
				count++;
				power = pow(2,count)+i;
			}
		}
	}
	return adjlist;
}

int main(int argc, char const *argv[])
{
	long n, p, q;
	std::cin>>n>>p>>q;
	std::map<long, std::vector<long> > m = makeadjlist(n);
	//for(auto iterator = m.begin(); iterator != m.end(); iterator++) {
	//	std::cout<<"key"<<std::endl;
	//	std::cout<<iterator->first<<std::endl;
	//	std::cout<<"value"<<std::endl;
	//	for (long i : iterator->second){
	//		std::cout<<i<<std::endl;
	//	}
	//}
	std::cout<<bfs(m,p,q)+1<<std::endl;
	return 0;
}