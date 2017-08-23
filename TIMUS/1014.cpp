#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

std::vector<long> primeFactors(long n){
	std::vector<long> pfs;
	std::vector<long> falseret;
	long primes[] = {9,8,7,6,5,4,3,2};
	falseret.push_back(-1);
	int i;
	int pf;
	bool isThere;
	while (n>1){
		for (i=0; i<8; i++){
			isThere = false;
			if (n%primes[i]==0){
				pfs.push_back(primes[i]);
				n = n/primes[i];
				isThere = true;
				break;
			} 
		}
		if (isThere == false){
			return falseret;
		}
	}
	return pfs;
}

int main(int argc, char const *argv[])
{
	long x;
	std::cin>>x;
	if (x == 1){
		std::cout<<1<<std::endl;
		return 0;
	}
	if (x == 0){
		std::cout<<10<<std::endl;
		return 0;
	}
	std::vector<long> pf = primeFactors(x);
	if (pf[0]==-1){
		std::cout<<-1<<std::endl;
		return 0;
	}
	//std::vector<long> path = converttopf(pf);
	std::reverse(pf.begin(),pf.end());
	for (int j = 0; j<pf.size(); j++){
		std::cout<<pf[j];
	}
	std::cout<<std::endl;
	return 0;
}