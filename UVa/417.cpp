#include <iostream>
#include <map>
#include <string>

const std::string alpha = "abcdefghijklmnopqrstuvwxyz";

std::string increment(std::string x, char smallest = 'z'){
	//std::cout<<x<<std::endl;
	//std::cout<<smallest<<std::endl;
	if (x.size()==0){
		//std::cout<<"small"<<std::endl;
		return "";
	} else if (x[x.size()-1]!=smallest){
		x[x.size()-1]++;
		return x;
	} else {
		x.pop_back();
		std::string incr = increment(x,smallest-1);
		if (incr.size()==0){
			return incr;
		} else {
			return incr+(char)(incr[incr.size()-1]+1);
		}
	}
}

std::string newCombination(int n){
	std::string ans = "";
	for (int i = 0; i<n; i++){
		ans+=alpha[i];
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	std::map<std::string, long> m;
	std::string x = "a";
	for (int i = 1; i<83681; i++){
		m[x]=i;
		int len = x.size();
		x=increment(x);
		if (x.size()==0){
			x=newCombination(len+1);
		}
	}
	m[x]=83681;
	
	std::string line;
	while (std::getline(std::cin, line)){
		if (line.size()==0){
			return 0;
		}
		if (m.count(line)==0){
			std::cout<<0<<std::endl;
		} else {
			std::cout<<m[line]<<std::endl;
		}
		//std::getline(std::cin, line);
	}
	return 0;
	return 0;
}