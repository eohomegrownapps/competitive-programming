#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	while (n!=0){
		std::map<long long, int> m;
		m.clear();
		int max = -1;
		for (int j = 0; j<n; j++){
			int names[5];
			for (int i = 0; i<5; i++){
				int temp;
				std::cin>>temp;
				names[i]=temp;
			}
			std::sort(names, names+5);
			long long label = 0;
			int count = 0;
			for (int i = 12; i>-1; i-=3){
				label+=names[count]*std::pow(10,i);
				//std::cout<<label<<std::endl;
				count++;
			}
			//std::cout<<label<<std::endl;
			if (m.find(label)==m.end()){
				m[label] = 1;
			} else {
				m[label]++;
			}
			if (m[label]>max){
				max = m[label];
			}
		}
		int count = 0;
		//std::cout<<max<<std::endl;
		for (auto i:m){
			if (i.second==max){
				count+=max;
			}
		}
		std::cout<<count<<std::endl;
		std::cin>>n;
	}
	return 0;
}