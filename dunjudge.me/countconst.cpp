#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> dfs(std::vector<int> unvisited,std::vector<std::vector<int> > adjlist, int node){
	std::vector<int>::iterator find = std::find(unvisited.begin(), unvisited.end(), node);
	unvisited.erase(find);
	for (int i = 0; i<adjlist[node-1].size(); i++){
		if (std::find(unvisited.begin(), unvisited.end(), adjlist[node-1][i]) != unvisited.end()){
			unvisited = dfs(unvisited,adjlist,adjlist[node-1][i]);
		}
	}
	return unvisited;
}

int main(int argc, char const *argv[])
{
	int y,x;
	std::cin>>y>>x;
	int hunny[y][x];
	char temp;
	int a,b;
	int n = 1;
	std::vector<int> unvisited;
	for (a = 0; a<y; a++){
		for (b = 0; b<x; b++){
			std::cin>>temp;
			if (temp == '*'){
				hunny[a][b] = n;
				unvisited.push_back(n);
				n++;
			} else {
				hunny[a][b] = 0;
			}
		}
	}
	n--;
	std::vector<std::vector<int> > adjlist(n);
	int c,d;
	for (c = 0; c<y; c++){
		for (d = 0; d<x; d++){
			//i,j+1 i+1,j
			if (hunny[c][d]>0){
				if (d+1<x){
					if (hunny[c][d+1]>0){
						adjlist[hunny[c][d]-1].push_back(hunny[c][d+1]);
						adjlist[hunny[c][d+1]-1].push_back(hunny[c][d]);
					}
				}
				if (c+1<y){
					if (hunny[c+1][d]>0){
						adjlist[hunny[c][d]-1].push_back(hunny[c+1][d]);
						adjlist[hunny[c+1][d]-1].push_back(hunny[c][d]);
					}
				}
			}
		}
	}
	int num = 0;
	while (unvisited.size()!=0){
		unvisited = dfs(unvisited,adjlist,unvisited[0]);
		num++;
	}
	std::cout<<num<<std::endl;
	return 0;
}