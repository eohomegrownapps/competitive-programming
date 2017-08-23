#include <iostream>
#include <vector>
#include <array>
#include <cmath>
long jump(int rows, int cols, std::vector<std::vector<int> > rocks){
	//y then x - row then col.
	std::vector<std::vector<long> > x;
	std::vector<long> row;
	row.clear();
	std::vector<long> squares;
	for (int i = 0; i<rows; i++){
		squares.push_back(i*i);
	}
	for (int i = 0; i<rows; i++){
		for (int j = 0; j<cols; j++){
			row.push_back(-1);
		}
		x.push_back(row);
		row.clear();
	}
	for (int i = 0; i<rows; i++){
		if (rocks[i][0]==1){
			x[i][0] = 0;
		}
	}
	long finalans;
	for (int j = 1; j<cols; j++){
		for (int k = 0; k<rows; k++){
			long minimum = -1;
			if (rocks[k][j]==1){
				for (int l = 0; l<rows; l++){
					if (x[l][j-1]!=-1){
						long square = (squares[std::abs(l-k)])+x[l][j-1];
						if (minimum==-1){
							minimum = square;
						} else if (square<minimum){
							minimum = square;
						}
					}
				}
				x[k][j] = minimum;
				finalans = minimum;
			}
		}
	}
	long m = -1;
	for (int p = 0; p<rows; p++){
		long temp = x[p][cols-1];
		if (temp!=-1){
			if (m==-1){
				m = temp;
			} else if (temp<m){
				m=temp;
			}
		}
	}
	return m;
}

int main(int argc, char const *argv[])
{
	int cols,rows;
	std::cin>>cols>>rows;
	char num;
	std::vector<std::vector<int> > v;
	std::vector<int> row;
	for (int i = 0; i<rows; i++){
		for (int j = 0; j<cols; j++){
			std::cin>>num;
			if (num=='1'){
				row.push_back(1);
			} else {
				row.push_back(0);
			}
		}
		v.push_back(row);
		row.clear();
	}
	std::cout<<jump(rows,cols,v)<<std::endl;
	return 0;
}