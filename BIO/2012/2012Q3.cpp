#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <queue>
std::string numbers[10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

bool isConnected(int a, int b){
	std::string astr = std::to_string(a);
	std::array<int,26> av;
	av.fill(0);
	std::string bstr = std::to_string(b);
	std::array<int,26> bv;
	bv.fill(0);
	std::string tempstring;
	char tempchar;
	int tempint;
	for (int i = 0; i<astr.length(); i++){
		tempchar = astr[i];
		tempint = (int)(tempchar)-'0';
		tempstring = numbers[tempint];
		//std::cout<<tempstring<<std::endl;
		for (int j = 0; j<tempstring.length(); j++){
			av[(int)tempstring[j]-65]+=1;
		}
	}
	for (int i = 0; i<bstr.length(); i++){
		tempchar = (char)bstr[i];
		tempint = (int)tempchar-'0';
		tempstring = numbers[tempint];
		//std::cout<<tempstring<<std::endl;
		for (int j = 0; j<tempstring.length(); j++){
			bv[(int)tempstring[j]-65]+=1;
		}
	}
	int diff = 0;
	for (int i = 0; i<26; i++){
		diff += std::abs(av[i]-bv[i]);
	}
	if (diff>5){
		return false;
	}
	return true;
}

std::vector<std::vector<int> > adjlist(){
	std::vector<std::vector<int> > adjlist;
	std::vector<int> v;
	for (int i = 0; i<1000; i++){
		adjlist.push_back(v);
	}
	for (int i = 0; i<1000; i++){
		for (int j = i+1; j<1000; j++){
			if (isConnected(i,j)){
				adjlist[i].push_back(j);
				adjlist[j].push_back(i);
			}
		}
	}
	return adjlist;
}

int bfs(std::vector<std::vector<int> > adjlist, int nodea, int nodeb){
	std::array<int,1000> distance;
	distance.fill(-1);
	std::queue<int> q;
	q.push(nodea);
	distance[nodea] = 0;
	int curnode;
	int tempnode;
	while (q.size()!=0){
		curnode = q.front();
		q.pop();
		for (int i = 0; i<adjlist[curnode].size(); i++){
			tempnode = adjlist[curnode][i];
			if (distance[tempnode]==-1){
				distance[tempnode] = distance[curnode]+1; 
				q.push(tempnode);
			}
			if (tempnode==nodeb){
				return distance[tempnode];
			}
		}
	}
	return -1;
}

int connectednos(int a, int b, std::vector<std::vector<int> > adjlist){
	int nsize = bfs(adjlist,a,b);
	return nsize;
}

int main(int argc, char const *argv[])
{
	int a,b,c,d,e,f;
	std::cin>>a>>b>>c>>d>>e>>f;
	std::vector<std::vector<int> > v = adjlist();
	std::cout<<connectednos(a,b,v)<<std::endl;
	std::cout<<connectednos(c,d,v)<<std::endl;
	std::cout<<connectednos(e,f,v)<<std::endl;
	return 0;
}