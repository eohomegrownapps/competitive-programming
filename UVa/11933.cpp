#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
	long n;
	std::cin>>n;
	while (n!=0){
		std::string bin = std::bitset<32>(n).to_string();
		std::string ans1 = "";
		std::string ans2 = "";
		int count = 0;
		for (int i = 31; i>=0; i--){
			if (bin[i]=='1'){
				count++;
				if (count%2==1){
					ans1.push_back('1');
					ans2.push_back('0');
				} else {
					ans1.push_back('0');
					ans2.push_back('1');
				}
			} else {
				ans1.push_back('0');
				ans2.push_back('0');
			}
		}
		std::reverse(ans1.begin(), ans1.end());
		std::reverse(ans2.begin(), ans2.end());
		unsigned long dec1 = std::bitset<32>(ans1).to_ulong();
		unsigned long dec2 = std::bitset<32>(ans2).to_ulong();
		std::cout<<dec1<<" "<<dec2<<std::endl;
		std::cin>>n;
	}
	return 0;
}