#include <iostream>
#include <array>

bool isSquarePresent(std::array<std::array<char, 500>,500> bigsquare, std::array<std::array<char, 500>,500> littlesquare, int b, int x, int y){
	for (int n = 0; n<b; n++){
		for (int m = 0; m<b; m++){
			if (bigsquare[m+x][n+y]!=littlesquare[m][n]){
				return false;
			}
		}
	}
	return true;
}

int checkSquare(std::array<std::array<char, 500>,500> bigsquare, std::array<std::array<char, 500>,500> littlesquare, int a, int b){
	int squares = 0;
	for (int y = 0; y<a-b+1; y++){
		for (int x = 0; x<a-b+1; x++){
			if (isSquarePresent(bigsquare,littlesquare,b,x,y)){
				squares++;
			}
		}
	}
	return squares;
}

std::array<std::array<char, 500>,500> rotateSquareClockwise(std::array<std::array<char, 500>,500> littlesquare, int b){
	std::array<std::array<char, 500>,500> newlittlesquare;
	for (int y = 0; y<b; y++){
		for (int x = 0; x<b; x++){
			newlittlesquare[x][y]=littlesquare[y][b-1-x];
		}
	}
	return newlittlesquare;
}

int main(int argc, char const *argv[])
{
	int a,b;
	std::cin>>a>>b;
	while (a!=0){
		std::array<std::array<char, 500>,500> bigsquare;
		std::array<std::array<char, 500>,500> littlesquare;
		char temp;
		for (int y = 0; y<a; y++){
			for (int x = 0; x<a; x++){
				std::cin>>temp;
				bigsquare[x][y]=temp;
			}
		}
		for (int y = 0; y<b; y++){
			for (int x = 0; x<b; x++){
				std::cin>>temp;
				littlesquare[x][y]=temp;
			}
		}
		std::cout<<checkSquare(bigsquare,littlesquare,a,b)<<" ";
		littlesquare = rotateSquareClockwise(littlesquare,b);
		std::cout<<checkSquare(bigsquare,littlesquare,a,b)<<" ";
		littlesquare = rotateSquareClockwise(littlesquare,b);
		std::cout<<checkSquare(bigsquare,littlesquare,a,b)<<" ";
		littlesquare = rotateSquareClockwise(littlesquare,b);
		std::cout<<checkSquare(bigsquare,littlesquare,a,b)<<std::endl;
		std::cin>>a>>b;
	}
	return 0;
}