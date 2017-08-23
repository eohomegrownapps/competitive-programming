#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

std::vector<int> bfs(std::vector<std::vector<int> > adjlist, int node, int destnode){
	//std::vector<int> distances;
	std::vector<int> unvisited;
	for (int i = 0; i<adjlist.size(); i++){
		//distances.push_back(-1);
		unvisited.push_back(1);
	}
	//distances[node] = 0;
	std::vector<int> nodesavailable;
	int currentdistance = 0;
	int i, j;
	nodesavailable.push_back(node);
	std::vector<int> newnodesavailable;
	while (true){
		for (i = 0; i<nodesavailable.size(); i++){
			for (j = 0; j<nodesavailable[i].size(); j++){
				if (unvisited[j]==1){
					if (j == destnode){
						return currentdistance+1;
					}
					newnodesavailable.push_back(j);
				}
			}
		}
		nodesavailable = newnodesavailable;
		newnodesavailable.clear();
		currentdistance++;
	}
	return distances;
}

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int> > adjlist(n);
	int x,y,z,i,j,k,node,ncount;
	ncount = 0;
	std::cin>>z>>x>>y;
	char ch;
	vector<vector<vector<int> > > vec (z,vector<vector<int> >(y,vector <int>(x,0)));
	for (i = 0; i<z; i++){
		for (j = 0; j<y; j++){
			//right, down, bottom
			for (k = 0; k<x; k++){
				std::cin>>ch;
				if (ch=='#'){
					vec[i][j][k]=-1;
				} else {
					vec[i][j][k]=ncount;
					ncount++;
					
				}
			}
		}
	}


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