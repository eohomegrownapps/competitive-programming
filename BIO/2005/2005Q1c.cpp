#include <iostream>
#include <string>
#include <cmath>

int computeScore(int numerator){
	int denominator = 10000;
	while (true){
		if (numerator%5==0&&denominator%5==0){
			numerator/=5;
			denominator/=5;
		} else if (numerator%2==0&&denominator%2==0){
			numerator/=2;
			denominator/=2;
		} else {
			break;
		}
	}
	int score = -1;
	std::string num_string = std::to_string(numerator);
	std::string den_string = std::to_string(denominator);
	for (char c : num_string){
		if (score==-1){
			score=c-'0';
		} else {
			score*=c-'0';
		}
	}
	for (char c : den_string){
		if (score==-1){
			score=c-'0';
		} else {
			score*=c-'0';
		}
	}
	return score;
}

int main(int argc, char const *argv[])
{
	int score = 0;
	int numerator = -1;
	for (int i = 1; i<10000; i++){
		int temp = computeScore(i);
		if (temp>score){
			numerator = i;
			score = temp;
		}
	}
	std::cout<<score<<" "<<numerator<<std::endl;
	return 0;
}