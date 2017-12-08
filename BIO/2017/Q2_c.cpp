#include <iostream>
#include <vector>

std::vector<std::vector<int> > grid;
std::vector<int> playerPositions;
std::vector<int> playerModifiers;
void initialiseGrid(){
	std::vector<int> v;
	v.resize(11,0);
	for (int x = 0; x<11; x++){
		grid.push_back(v);
	}
}

void displayGrid(){
	for (int y = 0; y<11; y++){
		for (int x = 0; x<11; x++){
			std::cout<<grid[x][y]<<" ";
		}
		std::cout<<std::endl;
	}
}

int toDotX(int n){
	return 2*((n-1)%6);
}

int toDotY(int n){
	return 2*((n-1)/6);
}

bool checkPlaceUp(int dotx, int doty){
	//std::cout<<"place up"<<std::endl;
	if (doty>0){
		int checkx = dotx;
		int checky = doty-1;
		if (grid[checkx][checky]==0){
			grid[checkx][checky]=1;
			return true;
		}
	}
	return false;
}
bool checkPlaceRight(int dotx, int doty){
	//std::cout<<"place right"<<std::endl;
	if (dotx<10){
		int checkx = dotx+1;
		int checky = doty;
		if (grid[checkx][checky]==0){
			grid[checkx][checky]=1;
			return true;
		}
	}
	return false;
}
bool checkPlaceLeft(int dotx, int doty){
	//std::cout<<"place left"<<std::endl;
	if (dotx>0){
		int checkx = dotx-1;
		int checky = doty;
		if (grid[checkx][checky]==0){
			grid[checkx][checky]=1;
			return true;
		}
	}
	return false;
}
bool checkPlaceDown(int dotx, int doty){
	//std::cout<<"place down"<<std::endl;
	if (doty<10){
		int checkx = dotx;
		int checky = doty+1;
		if (grid[checkx][checky]==0){
			grid[checkx][checky]=1;
			return true;
		}
	}
	return false;
}

bool checkSquare(int x, int y, int player){
	if (grid[x-1][y]==1&&grid[x+1][y]==1&&grid[x][y-1]==1&&grid[x][y+1]==1){
		grid[x][y]=player;
		return true;
	}
	return false;
}

bool takeTurn(int player, bool modone){
	if (modone){
		playerPositions[player-1]+=1;
	} else {
		playerPositions[player-1]+=playerModifiers[player-1];
	}
	if (playerPositions[player-1]>36){
		playerPositions[player-1]-=36;
	}
	int position = playerPositions[player-1];
	int dotx = toDotX(position);
	int doty = toDotY(position);
	//std::cout<<dotx<<std::endl;
	//std::cout<<doty<<std::endl;
	int linex, liney;
	bool win = false;
	if (player==1){
		if (checkPlaceUp(dotx,doty)){
			linex=dotx;
			liney=doty-1;
			if (0<linex){
				if (checkSquare(linex-1,liney, player)){
					win = true;
				}
			}
			if (linex<10){
				if (checkSquare(linex+1,liney, player)){
					win = true;
				}
			}
		} else if (checkPlaceRight(dotx,doty)){
			linex=dotx+1;
			liney=doty;
			if (0<liney){
				if (checkSquare(linex,liney-1, player)){
					win = true;
				}
			}
			if (liney<10){
				if (checkSquare(linex,liney+1, player)){
					win = true;
				}
			}
		} else if (checkPlaceDown(dotx,doty)){
			linex=dotx;
			liney=doty+1;
			if (0<linex){
				if (checkSquare(linex-1,liney, player)){
					win = true;
				}
			}
			if (linex<10){
				if (checkSquare(linex+1,liney, player)){
					win = true;
				}
			}
		} else if (checkPlaceLeft(dotx,doty)){
			linex=dotx-1;
			liney=doty;
			if (0<liney){
				if (checkSquare(linex,liney-1, player)){
					win = true;
				}
			}
			if (liney<10){
				if (checkSquare(linex,liney+1, player)){
					win = true;
				}
			}
		} else {
			return takeTurn(player,true);
		}
	} else {
		if (checkPlaceUp(dotx,doty)){
			linex=dotx;
			liney=doty-1;
			if (0<linex){
				if (checkSquare(linex-1,liney, player)){
					win = true;
				}
			}
			if (linex<10){
				if (checkSquare(linex+1,liney, player)){
					win = true;
				}
			}
		} else if (checkPlaceLeft(dotx,doty)){
			linex=dotx-1;
			liney=doty;
			if (0<liney){
				if (checkSquare(linex,liney-1, player)){
					win = true;
				}
			}
			if (dotx<10){
				if (checkSquare(linex,liney+1, player)){
					win = true;
				}
			}
		} else if (checkPlaceDown(dotx,doty)){
			linex=dotx;
			liney=doty+1;
			if (0<linex){
				if (checkSquare(linex-1,liney, player)){
					win = true;
				}
			}
			if (linex<10){
				if (checkSquare(linex+1,liney, player)){
					win = true;
				}
			}
		} else if (checkPlaceRight(dotx,doty)){
			linex=dotx+1;
			liney=doty;
			if (0<liney){
				if (checkSquare(linex,liney-1, player)){
					win = true;
				}
			}
			if (dotx<10){
				if (checkSquare(linex,liney+1, player)){
					win = true;
				}
			}
		} else {
			return takeTurn(player,true);
		}
	}
	if (win){
		return true;
	} else {
		return false;
	}
}

bool meetsConditions(int p1, int m1, int p2, int m2){
	grid.clear();
	playerPositions.clear();
	playerModifiers.clear();
	initialiseGrid();
	//displayGrid();
	int t = 60;
	playerPositions.push_back(p1);
	playerPositions.push_back(p2);
	playerModifiers.push_back(m1);
	playerModifiers.push_back(m2);
	int playerToGo = 1;
	for (int i = 0; i<t; i++){
		bool goAgain = takeTurn(playerToGo,false);
		if (!goAgain){
			if (playerToGo==1){
				playerToGo=2;
			} else {
				playerToGo=1;
			}
		}
		//displayGrid();
	}
	int count = 0;
	for (int y = 1; y<=9; y+=2){
		for (int x = 1; x<=9; x+=2){
			int player = grid[x][y];
			if (player==2){
				count++;
			}
		}
	}
	if (count==25){
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int count = 0;
	int check = 0;
	for (int p1 = 1; p1<=36; p1++){
		for (int m1 = 1; m1<=35; m1++){
			for (int p2 = 1; p2<=36; p2++){
				for (int m2 = 1; m2<=35; m2++){
					if (meetsConditions(p1,m1,p2,m2)){
						count++;
					}
					check++;
					std::cout<<check<<std::endl;
				}
			}
		}
	}
	std::cout<<count<<std::endl;
	return 0;
}