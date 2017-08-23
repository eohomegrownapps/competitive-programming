#include <iostream>
#include <array>

void printBoard(std::array<std::array<int, 7>, 6> &board){
	for (int y = 0; y<6; y++){
		for (int x = 0; x<7; x++){
			switch(board[x][y]){
				case 0:
					std::cout<<"-";
					break;
				case 1:
					std::cout<<"*";
					break;
				case 2:
					std::cout<<"o";
					break;
			}
		}
		std::cout<<std::endl;
	}
}

int checkDraw(std::array<std::array<int, 7>, 6> &board){
	int zeroes = 0;
	for (int x = 0; x<7; x++){
		for (int y = 0; y<6; y++){
			if (board[x][y]==0){
				zeroes++;
			}
		}
	}
	if (zeroes==0){
		return 0;
	}
	return -1;
}

void playMove(int player, int column, std::array<std::array<int, 7>, 6> &board){
	for (int i = 5; i>=0; i--){
		if (board[column][i]==0){
			board[column][i]=player;
			return;
		}
	}
}

void unPlayMove(int player, int column, std::array<std::array<int, 7>, 6> &board){
	for (int i = 0; i<6; i++){
		if (board[column][i]==player){
			board[column][i]=0;
			return;
		}
	}
}

bool checkWin(int player, std::array<std::array<int, 7>, 6> &board){
	//right diagonals
	for (int x = 3; x<7; x++){
		for (int y = 0; y<3; y++){
			if (board[x][y]==player&&
				board[x-1][y+1]==player&&
				board[x-2][y+2]==player&&
				board[x-3][y+3]==player){
				return true;
			}
		}
	}
	//left diagonals
	for (int x = 0; x<4; x++){
		for (int y = 0; y<3; y++){
			if (board[x][y]==player&&
				board[x+1][y+1]==player&&
				board[x+2][y+2]==player&&
				board[x+3][y+3]==player){
				return true;
			}
		}
	}
	//vertical
	for (int x = 0; x<7; x++){
		for (int y = 0; y<3; y++){
			if (board[x][y]==player&&
				board[x][y+1]==player&&
				board[x][y+2]==player&&
				board[x][y+3]==player){
				return true;
			}
		}
	}
	//horizontal
	for (int x = 0; x<4; x++){
		for (int y = 0; y<6; y++){
			if (board[x][y]==player&&
				board[x+1][y]==player&&
				board[x+2][y]==player&&
				board[x+3][y]==player){
				return true;
			}
		}
	}
	return false;
}

int nextMove(int player, std::array<std::array<int, 7>, 6> &board){
	int otherplayer=1;
	if (player==1){
		otherplayer=2;
	}
	//rule 1
	for (int i = 0; i<7; i++){
		if (board[i][0]==0){
			playMove(player,i,board);
			if (checkWin(player,board)){
				return player;
			} else {
				unPlayMove(player,i,board);
			}
		}
	}
	//rule 2
	for (int i = 0; i<7; i++){
		if (board[i][0]==0){
			playMove(otherplayer,i,board);
			if (checkWin(otherplayer,board)){
				unPlayMove(otherplayer,i,board);
				playMove(player,i,board);
				return checkDraw(board);
			} else {
				unPlayMove(otherplayer,i,board);
			}
		}
	}
	//rule 3
	for (int i = 0; i<7; i++){
		if (board[i][0]==0){
			playMove(player,i,board);
			return checkDraw(board);
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	//player=1, player=2, draw=0, no=-1
	std::array<std::array<int, 7>, 6> board;
	for (int x = 0; x<7; x++){
		for (int y = 0; y<6; y++){
			board[x][y]=0;
		}
		board[x].fill(0);
	}
	int n;
	std::cin>>n;
	int player = 1;
	for (int i = 0; i<n; i++){
		int temp;
		std::cin>>temp;
		playMove(player,temp-1,board);
		if (player==1){
			player=2;
		} else {
			player=1;
		}
	}
	std::cout<<std::endl;
	printBoard(board);
	std::cout<<std::endl;

	while (true){
		char c;
		std::cin>>c;
		if (c=='n'){
			int win = nextMove(player, board);
			std::cout<<std::endl;
			printBoard(board);
			std::cout<<std::endl;
			switch(win){
				case 0:
					std::cout<<"Draw"<<std::endl;
					return 0;
				case 1:
					std::cout<<"Player 1 wins"<<std::endl;
					return 0;
				case 2:
					std::cout<<"Player 2 wins"<<std::endl;
					return 0;
			}
			if (player==1){
				player=2;
			} else {
				player=1;
			}
		} else if (c=='r'){
			while (true){
				int win = nextMove(player, board);
				switch(win){
					case 0:
						std::cout<<std::endl;
						printBoard(board);
						std::cout<<std::endl;
						std::cout<<"Draw"<<std::endl;
						return 0;
					case 1:
						std::cout<<std::endl;
						printBoard(board);
						std::cout<<std::endl;
						std::cout<<"Player 1 wins"<<std::endl;
						return 0;
					case 2:
						std::cout<<std::endl;
						printBoard(board);
						std::cout<<std::endl;
						std::cout<<"Player 2 wins"<<std::endl;
						return 0;
				}
				if (player==1){
					player=2;
				} else {
					player=1;
				}
			}
		}
	}

	return 0;
}