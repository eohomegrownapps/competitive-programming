#include <string>
#include <vector>
#include <numeric>
#include <iostream>

long long factorial(long long n){
	if (n==0){
		return 1;
	}
	if (n==1){
		return 1;
	}
	return n*factorial(n-1);
}

std::string modernart(std::string arrangement, long long num){
	if (arrangement.length()==1){
		return arrangement;
	}
	char vals[4] = {'A','B','C','D'};
	std::vector<long long> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	for (char i : arrangement){
		if (i=='A'){
			v[0]+=1;
		}
		if (i=='B'){
			v[1]+=1;
		}
		if (i=='C'){
			v[2]+=1;
		}
		if (i=='D'){
			v[3]+=1;
		}
	}
	//for (int a = 0; a<4; a++){
	//	std::cout<<v[a]<<" ";
	//}
	//std::cout<<std::endl;
	long long count = 0;
	long long temp;
	int i;
	long long facttemp;
	for (i = 0; i<4; i++){
		if (v[i]!=0){
			v[i]-=1;
			facttemp = (factorial(v[0])*factorial(v[1])*factorial(v[2])*factorial(v[3]));
			//std::cout<<facttemp<<std::endl;
			temp = factorial(std::accumulate(v.begin(), v.end(),0))/facttemp;
			//std::cout<<temp<<std::endl;
			if (count+temp>=num){
				break;
			}
			v[i]+=1;
			count += temp;
		}
	}
	arrangement.clear();
	for (int j = 0; j<4; j++){
		for (int k = 0; k<v[j]; k++){
			arrangement.push_back(vals[j]);
		}
	}
	return vals[i]+modernart(arrangement,num-count);
}

int main(int argc, char const *argv[])
{
	long long a,b,c,d,n;
	std::cin>>a>>b>>c>>d>>n;
	char vals[4] = {'A','B','C','D'};
	std::vector<long long> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	std::string arrangement = "";
	for (int j = 0; j<4; j++){
		for (int k = 0; k<v[j]; k++){
			arrangement.push_back(vals[j]);
		}
	}
	std::cout<<modernart(arrangement,n)<<std::endl;
	return 0;
}