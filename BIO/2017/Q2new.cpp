#include <array>
#include <vector>
#include <iostream>

std::vector<int> availabledots(int dot){
	std::vector<int> v;
	//clockwise.
	if (dot==0){
		v.push_back(1);
		v.push_back(6);
		return v;
	}
	if (dot==5){
		v.push_back(11);
		v.push_back(4);
		return v;
	}
	if (dot==30){
		v.push_back(24);
		v.push_back(31);
		return v;
	}
	if (dot==35){
		v.push_back(29);
		v.push_back(34);
		return v;
	}
	if (dot<6){
		v.push_back(dot+1);
		v.push_back(dot+6);
		v.push_back(dot-1);
		return v;
	}
	if (dot>29){
		v.push_back(dot-6);
		v.push_back(dot+1);
		v.push_back(dot-1);
		return v;
	}
	if (dot%6==0){
		v.push_back(dot-6);
		v.push_back(dot+1);
		v.push_back(dot+6);
		return v;
	}
	if ((dot+1)%6==0){
		v.push_back(dot-6);
		v.push_back(dot+6);
		v.push_back(dot-1);
		return v;
	}
	v.push_back(dot-6);
	v.push_back(dot+1);
	v.push_back(dot+6);
	v.push_back(dot-1);
	return v;
}

std::vector<int> posingrid(int dot){
	int x = 2*(dot%6)+1;
	int y = (dot-(dot%6))/6;
	y = y*2+1;
	std::vector<int> v;
	v.push_back(x);
	v.push_back(y);
	return v;
}

void dots(int starta, int incra, int startb, int incrb, int turns){
	starta -= 1;
	startb -= 1;
	std::vector<int> awin;
	std::vector<int> bwin;
	int currenta, currentb;
	currenta = starta;
	currentb = startb;
	std::array<std::array<int,12>,12> grid;
	for (int i = 0; i<12; i++){
		for (int j = 0; j<12; j++){
			grid[i][j]=0;
		}
	}
	for (int i = 0; i<turns; i++){
		currenta+=incra;
		if (currenta>35){
			currenta-=36;
		}
		std::vector<int> va = availabledots(currenta);
		bool completed = false;
		while (completed==false){
			for (int i = 0; i<va.size(); i++){
				int curdot = va[i];
				std::cout<<curloc<<std::endl;
				std::cout<<curaloc<<std::endl;
				std::vector<int> curloc = posingrid(curdot);
				std::vector<int> curaloc = posingrid(currenta);
				if (curloc[0]==curaloc[0]){
					curloc[1] = (curloc[1]+curaloc[1])/2;
				} else {
					curloc[0] = (curloc[0]+curaloc[0])/2;
				}
				if (grid[curloc[0]][curloc[1]]==0){
					grid[curloc[0]][curloc[1]]=1;
					completed = true;
					break;
				}	
			}
			if (completed==false){
				currenta+=1;
				if (currenta>35){
					currenta-=36;
				}
			}
		}

		currentb+=incrb;
		if (currentb>35){
			currentb-=36;
		}
		std::vector<int> vb = availabledots(currentb);
		bool completedb = false;
		while (completedb==false){
			for (int i = 0; i<vb.size(); i++){
				int curdot = vb[i];
				std::vector<int> curloc = posingrid(curdot);
				std::vector<int> curbloc = posingrid(currentb);
				if (curloc[0]==curbloc[0]){
					curloc[1] = (curloc[1]+curbloc[1])/2;
				} else {
					curloc[0] = (curloc[0]+curbloc[0])/2;
				}
				if (grid[curloc[0]][curloc[1]]==0){
					grid[curloc[0]][curloc[1]]=1;
					completedb = true;
					break;
				}	
			}
			if (completedb==false){
				currentb+=1;
				if (currentb>35){
					currentb-=36;
				}
			}
		}

	}
	for (int i = 0; i<12; i++){
		for (int j = 0; j<12; j++){
			std::cout<<grid[i][j];
		}
		std::cout<<std::endl;
	}
}

int main(int argc, char const *argv[])
{
	int a,b,c,d,e;
	std::cin>>a>>b>>c>>d>>e;
	dots(a,b,c,d,e);
	return 0;
}