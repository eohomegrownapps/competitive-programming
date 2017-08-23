#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

long dp(std::vector<long> mapping){
	if (mapping.size()<7){
		return 1;
	}
	std::vector<long> board(mapping.size());
	std::fill(board.begin(), board.end(),-1);
	bool changes = true;
	long minimum;
	while (changes==true){
		changes = false;
		for (long i = 0; i<6; i++){
			board[mapping[i]]=1;
		}
		for (long j = 6; j<mapping.size(); j++){
			//min from 6 spaces ago
			minimum = -1;
			for (long k = j-1; k>j-7; k--){
				if (board[k]!=-1){
					if (minimum==-1||board[k]<minimum){
						minimum = board[k];
					}
				}
			}
			if (minimum!=-1){
				minimum+=1;
			}
			if ((board[mapping[j]]==-1&&minimum!=-1)||(board[mapping[j]]>minimum&&minimum!=-1)){
				board[mapping[j]]=minimum;
				changes = true;
			}
		}
	}
	return board[mapping.size()-1];
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
	long dist = dp(mapping);
	std::cout<<dist<<std::endl;
	return 0;
}