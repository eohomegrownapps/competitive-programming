#include <iostream>
#include <array>

bool win(char a, char b){
	//true if a beats b
	if ((a=='P'&&b=='R')||(a=='R'&&b=='S')||(a=='S'&&b=='P')){
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int t;
	std::cin>>t;
	for (int i = 0; i<t; i++){
		int r,c,n;
		std::cin>>r>>c>>n;
		std::array<std::array<char, 100>, 100> empty;
		std::array<std::array<char, 100>, 100> rocks;
		char ch;
		for (int y = 0; y<r; y++){
			for (int x = 0; x<c; x++){
				std::cin>>ch;
				rocks[x][y]=ch;
			}
		}
		std::array<std::array<char, 100>, 100> newrocks;
		for (int d = 0; d<n; d++){
			//horizontal check
			for (int y = 0; y<r; y++){
				for (int x = 0; x<c-1; x++){
					char checka = rocks[x][y];
					char checkb = rocks[x+1][y];
					if (checka!=checkb){
						if (win(checka,checkb)){
							//inhabit checkb's land
							newrocks[x+1][y]=checka;
						} else {
							newrocks[x][y]=checkb;
						}
					}
				}
			}
			for (int y = 0; y<r-1; y++){
				for (int x = 0; x<c; x++){
					char checka = rocks[x][y];
					char checkb = rocks[x][y+1];
					if (checka!=checkb){
						if (win(checka,checkb)){
							//inhabit checkb's land
							newrocks[x][y+1]=checka;
						} else {
							newrocks[x][y]=checkb;
						}
					}
				}
			}
			for (int y = 0; y<r; y++){
				for (int x = 0; x<c; x++){
					if ((newrocks[x][y]!='R')&&(newrocks[x][y]!='S')&&(newrocks[x][y]!='P')){
						newrocks[x][y]=rocks[x][y];
					}
				}
			}
			rocks = newrocks;
			newrocks = empty;
		}
		for (int y = 0; y<r; y++){
			for (int x = 0; x<c; x++){
				std::cout<<rocks[x][y];
			}
			std::cout<<std::endl;
		}
		if (i!=t-1){
			std::cout<<std::endl;
		}
	}
	return 0;
}