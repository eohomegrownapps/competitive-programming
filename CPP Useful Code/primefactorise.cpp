#include <vector>
#include <cmath>

std::vector<long> primefactorise (long num, std::vector<long> pfs = std::vector<long>()){
	//just use primefactorise(long) and it will give you a sorted list of PFs
	long double sqrt = std::sqrt(num);
	if (num==1){
		return pfs;
	}
	for (int i = 2; i<sqrt+1; i++){
		if (num%i==0){
			pfs.push_back(i);
			return primefactorise(num/i, pfs);
		}
	}
	pfs.push_back(num);
	return pfs;
}

//e.g.
#include <iostream>

int main(int argc, char const *argv[])
{
	long x;
	std::cin>>x;
	std::vector<long> v = primefactorise(x);
	for (long i = 0; i<v.size(); i++){
		std::cout<<v[i]<<std::endl;
	}
	return 0;
}