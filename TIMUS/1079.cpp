#include <iostream>

long maximum(long n){
	long seq[n];
	long max = 0;
	seq[0] = 0;
	seq[1] = 1;
	for (long i = 0; i<n; i++){
		if (seq[i]>max){
			max=seq[i];
		}
		if (i*2<n){
			seq[i*2] = seq[i];
		}
		if (i*2+1<n){
			seq[i*2+1] = seq[i]+seq[i+1];
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	long x;
	std::cin>>x;
	while (x!=0){
		std::cout<<maximum(x+1)<<std::endl;
		std::cin>>x;
	}
	return 0;
}