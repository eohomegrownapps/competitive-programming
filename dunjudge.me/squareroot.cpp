#include <iostream>
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

int main(int argc, char const *argv[])
{
	long n;
	std::cin>>n;
	std::vector<long> a;
	std::vector<long> v = primefactorise(n,a);
	long squarecheck = -1;
	long squarecount = 0;
	for (long i = 0; i<v.size(); i++){
		if (v[i]!=squarecheck){
			if (squarecount%2!=0){
				std::cout<<"no"<<std::endl;
				return 0;
			}
			squarecheck = v[i];
			squarecount = 1;
		}
		else {
			squarecount += 1;
		}
	}
	if (squarecount%2!=0){
		std::cout<<"no"<<std::endl;
		return 0;
	}
	std::cout<<"yes"<<std::endl;
	/* code */
	return 0;
}