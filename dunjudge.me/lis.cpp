#include <iostream>
#include <vector>

long lis(std::vector<long> seq){
	long lseq[seq.size()];
	lseq[0] = 1;
	long iter;
	long max;
	long max2 = 0;
	for (long i = 1; i<seq.size(); i++){
		max = 0;
		for (iter = 0; iter<i; iter++){
			if (seq[iter]<seq[i]){
				if (lseq[iter]>max){
					max = lseq[iter];
				}
			}
		}
		lseq[i]=max+1;
		if (lseq[i]>max2){
			max2=lseq[i];
		}
	}
	return max2;
}

int main(int argc, char const *argv[])
{
	long n;
	std::cin>>n;
	std::vector<long> v;
	long temp;
	for (long i = 0; i<n; i++){
		std::cin>>temp;
		v.push_back(temp);
	}
	if (n==1){
		std::cout<<1<<std::endl;
		return 0;
	}
	std::cout<<lis(v)<<std::endl;
	return 0;
}