#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

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
	int y,x,a,b,n,average,c,d,num;
	int hunny[y][x];
	char temp;
	std::vector<int> unvisited;
	std::vector<std::vector<int> > adjlist(n);
	int numofrepeats;
	std::cin>>numofrepeats;
	for (int z = 0; z<numofrepeats; z++){
		std::cin>>y>>x;
		n = 1;
		average = 0;
		unvisited.clear();
		adjlist.clear();l
		for (a = 0; a<y; a++){
			for (b = 0; b<x; b++){
				std::cin>>temp;
				if (temp != '#'){
					hunny[a][b] = n;
					unvisited.push_back(n);
					n++;
					if (temp == '*'){
						average++;
					}
				} else {
					hunny[a][b] = 0;
				}
			}
		}
		n--;
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
		num = 0;
		while (unvisited.size()!=0){
			unvisited = dfs(unvisited,adjlist,unvisited[0]);
			num++;
		}
		std::cout<<std::fixed<<std::setprecision(2)<<average/num<<std::endl;
	}
	return 0;
}