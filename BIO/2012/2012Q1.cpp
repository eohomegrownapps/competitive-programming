#include <vector>
#include <cmath>
#include <iostream>

std::vector<long> primef(long n){
	std::vector<long> v;
	long sqrt;
	bool nofactors;
	long i;
	while (n!=1){
		sqrt = (long)std::ceil(std::sqrt(n));
		nofactors = true;
		for (i = 2; i<sqrt+1; i++){
			if (n%i==0){
				nofactors = false;
				break;
			}
		}
		if (nofactors==true){
			v.push_back(n);
			return v;
		}
		v.push_back(i);
		n = n/i;
	}
	return v;
}

int main(int argc, char const *argv[])
{
	long n;
	std::cin>>n;
	std::vector<long> v = primef(n);
	std::vector<long> visited;
	long multtotal = 1;
	for (long t : v){
		if(std::find(visited.begin(), visited.end(),t)==visited.end()){
			multtotal*=t;
			visited.push_back(t);
		}
	}
	std::cout<<multtotal<<std::endl;
	return 0;
}