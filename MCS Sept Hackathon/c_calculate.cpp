#include <iostream>
#include <algorithm>
#include <vector>

long factorial(int num){
	long ans = 1;
	for (int i = 1; i<num+1; i++){
		ans = ans*i;
	}
	return ans;
}

bool isCircle(std::vector<int> circle){
	int primes[] = {2,3,5,7,11,13,17,19,23};
	int sum;
	for (int i = 0; i<circle.size()-1; i++){
		sum = circle[i]+circle[i+1];
		if (std::find(std::begin(primes),std::end(primes),sum)==std::end(primes)){
			return false;
		}
	}
	sum = circle[0]+circle[circle.size()-1];
	if (std::find(std::begin(primes),std::end(primes),sum)==std::end(primes)){
		return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	int i,j,l;
	long fact;
	long k;
	for (i = 4; i<13; i+=2){
	//for (i = 4; i<7; i+=2){
		std::cout<<"---"<<i<<"---"<<std::endl;
		v.clear();
		for (j = 1; j<i+1; j++){
			v.push_back(j);
		}
		fact = factorial(i-1);
		for (k = 0; k<fact; k++){
			std::next_permutation(v.begin()+1, v.end());
			if (isCircle(v)){
				for (l=0; l<v.size(); l+=1){
					if (l==v.size()-1){
						std::cout<<v[l]<<"\\n";
					} else {
						std::cout<<v[l]<<",";
					}
				}
			}
		}
	}
	return 0;
}