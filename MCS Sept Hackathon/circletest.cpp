#include <iostream>
#include <algorithm>
#include <vector>
bool isCircle(std::vector<int> circle){
	int primes[] = {2,3,5,7,11,13,17,19,23};
	int sum;
	for (int i = 0; i<circle.size()-1; i++){
		sum = circle[i]+circle[i+1];
		std::cout<<sum<<std::endl;
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
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(6);
	std::cout<<isCircle(v)<<std::endl;
	return 0;
}