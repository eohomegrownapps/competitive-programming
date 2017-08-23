#include <vector>
#include <iostream>
#include <cmath>
std::vector<int> nthstone(long n, int stones){
	int bins[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
	std::vector<int> v;
	for (int i = 0; i<stones; i++){
		if ((n&bins[stones-1-i]) != 0){
			v.push_back(1);
		} else{
			v.push_back(0);
		}
	}
	return v;
}

long stonediff(std::vector<long> stones, std::vector<int> use, int num, long sum){
	long count = 0;
	for (int i = 0; i<num; i++){
		if (use[i]==1){
			count += stones[i];
		}
	}
	return labs(count-(sum-count));
}

int main(int argc, char const *argv[])
{
	std::vector<int> use;
	//std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
	int num;
	std::cin>>num;
	std::vector<long> stones;
	long a;
	for (int z = 0; z<num; z++){
		std::cin>>a;
		stones.push_back(a);
	}
	long sum = 0;
	for (int x = 0; x<num; x++){
		sum += stones[x];
	}
	long stop = std::pow(2,num);
	long sdiff = -1;
	long tsdiff;
	for (long i = 1; i<stop+1;i++){
		use = nthstone(i,num);
		tsdiff = stonediff(stones,use,num,sum);
		if (sdiff == -1){
			sdiff = tsdiff;
		} else if (tsdiff<sdiff){
			sdiff = tsdiff;
		}
	}
	std::cout<<sdiff<<std::endl;
	return 0;
}