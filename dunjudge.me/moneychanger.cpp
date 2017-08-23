#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	int num[10000];
	int n,v;
	std::cin>>n>>v;
	std::vector<int> coins;
	for (int i = 0; i<n; i++){
		int c;
		std::cin>>c;
		coins.push_back(c);
	}
	for (int i = 1; i<v+1; i++){
		num[i]=10005;
	}
	for (int i = 1; i<v+1; i++){
		int min = 10005;
		for (int item : coins){
			if (i-item>0){
				if (num[i-item]<min){
					min=num[i-item];
				}
			}
			if (item==i){
				min=0;
				break;
			}
		}
		min++;
		num[i]=min;
	}
	if (num[v]>10004){
		std::cout<<-1<<std::endl;
	} else {
		std::cout<<num[v]<<std::endl;
	}
	return 0;
}