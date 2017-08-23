#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>

int main(int argc, char const *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)){
		int n;
		try {
			n = std::stoi(line);
		} catch(...){
			return 0;
		}
		int temp;
		std::vector<int> d;
		for (int i = 0; i<std::pow(2.0,n); i++){
			std::cin>>temp;
			d.push_back(temp);
		}
		std::vector<int> dims;
		for (int x = 0; x<d.size(); x++){
			int potency = 0;
			std::string bin = std::bitset<15>(x).to_string();
			int currentPower = std::pow(2.0,n-1);
			for (int y = 15-n; y<15; y++){
				int otherNumber;
				if (bin[y]=='0'){
					otherNumber = x+currentPower;
				} else {
					otherNumber = x-currentPower;
				}
				potency+=d[otherNumber];
				currentPower/=2;	
			}
			dims.push_back(potency);
		}
		int maxWeight = 0;
		for (int j = 0; j<std::pow(2.0,n)-1; j++){
			int currentWeight = dims[j];
			std::string bin = std::bitset<15>(j).to_string();
			std::string binary = bin.substr(bin.size() - n);
			int currentPower = std::pow(2.0,n-1);
			for (int k = 0; k<binary.size(); k++){
				if (binary[k]=='0'){
					if (currentWeight+dims[j+currentPower]>maxWeight){
						maxWeight=currentWeight+dims[j+currentPower];
					}
				}
				currentPower/=2;
			}
		}
		std::cout<<maxWeight<<std::endl;
		std::getline(std::cin, line);
	}
	return 0;
}