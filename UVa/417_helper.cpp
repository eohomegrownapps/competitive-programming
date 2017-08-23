#include <iostream>
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
	std::cout<<"{";
	std::string x="a";
	for (int i = 1; i<83681; i++){
		std::cout<<"std::make_pair(\""<<x<<"\","<<i<<"),";
		int len = x.size();
		x=increment(x);
		if (x.size()==0){
			x=newCombination(len+1);
		}
	}
	std::cout<<"std::make_pair(\""<<x<<"\","<<83681<<")};"<<std::endl;
	return 0;
}