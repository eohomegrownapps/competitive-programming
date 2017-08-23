#include <iostream>
#include <stack>
#include <queue>
#include <vector>

int unload(std::stack<int> &cargo, std::queue<int> &platform, int x, int maxqueuesize, int &unloaded){
	int minutesSpent = 0;
	while (true){
		if (cargo.size()>0){
			if (cargo.top()==x){
				cargo.pop();
				minutesSpent++;
				unloaded++;
			} else if (platform.size()<maxqueuesize){
				platform.push(cargo.top());
				cargo.pop();
				minutesSpent++;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	return minutesSpent;
}

int load(std::stack<int> &cargo, std::queue<int> &platform, int maxcargosize){
	int minutesSpent = 0;
	while (platform.size()>0&&cargo.size()<maxcargosize){
		cargo.push(platform.front());
		platform.pop();
		minutesSpent++;
	}
	return minutesSpent;
}

int main(int argc, char const *argv[])
{
	int set;
	std::cin>>set;
	for (int i = 0; i<set; i++){
		int n,maxcargosize,maxqueuesize;
		std::cin>>n>>maxcargosize>>maxqueuesize;
		std::vector<std::queue<int> > platforms;
		int parcels = 0;
		for (int j = 0; j<n; j++){
			std::queue<int> temp;
			int qi;
			std::cin>>qi;
			for (int k = 0; k<qi; k++){
				int temp2;
				std::cin>>temp2;
				temp.push(temp2-1);
				parcels++;
			}
			platforms.push_back(temp);
		}
		int unloaded = 0;
		int currentStation = 0;
		int time = 0;
		std::stack<int> cargo;
		while (unloaded!=parcels){
			if (currentStation==n){
				currentStation=0;
			}
			time+=unload(cargo,platforms[currentStation],currentStation,maxqueuesize,unloaded);
			time+=load(cargo,platforms[currentStation],maxcargosize);
			time+=2;
			currentStation++;
		}
		time-=2;
		std::cout<<time<<std::endl;
	}
	return 0;
}