#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string advanceGrid(std::string x){
	std::string y = "";
	std::vector<int> v;
	for (int i = 0; i<9; i++){
		v.push_back(x[i]-'0');
	}
	y+=std::to_string((v[1]+v[3])%2);
	y+=std::to_string((v[0]+v[2]+v[4])%2);
	y+=std::to_string((v[1]+v[5])%2);
	y+=std::to_string((v[0]+v[4]+v[6])%2);
	y+=std::to_string((v[1]+v[3]+v[5]+v[7])%2);
	y+=std::to_string((v[2]+v[4]+v[8])%2);
	y+=std::to_string((v[3]+v[7])%2);
	y+=std::to_string((v[4]+v[6]+v[8])%2);
	y+=std::to_string((v[5]+v[7])%2);
	return y;
}

int inVector(std::vector<std::string> v, std::string x){
	for (int i = 0; i<v.size(); i++){
		if (v[i]==x){
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	for (int i = 0; i<n; i++){
		std::string grid = "";
		char temp;
		for (int j = 0; j<9; j++){
			std::cin>>temp;
			grid += temp;
		}
		//std::cout<<grid<<std::endl;
		std::vector<std::string> pastgrids;
		pastgrids.push_back(grid);
		std::string newgrid = advanceGrid(grid);
		//std::cout<<newgrid<<std::endl;
		int x = inVector(pastgrids,newgrid);
		while (x==-1){
			pastgrids.push_back(newgrid);
			newgrid = advanceGrid(newgrid);
			//std::cout<<newgrid<<std::endl;
			x = inVector(pastgrids,newgrid);
		}
		std::cout<<x-1<<std::endl;
	}
	return 0;
}