#include <vector>
#include <iostream>
#include <map>

std::vector<int> scenes;
std::map<std::vector<int>, long> map;


long combinations(std::vector<int> currentscenes){
	std::map<std::vector<int>, long>::iterator itr = map.find(currentscenes);
	if (itr!=map.end()){
		return itr->second;
	}
	std::vector<int> s;
	long total = 0;
	bool checked = false;
	for (int i = 0; i<currentscenes.size(); i++){
		if (currentscenes[i]<scenes[i]){
			if (i==0){
				s = currentscenes;
				s[i]++;
				total+=combinations(s); 
			} else if (currentscenes[i-1]>currentscenes[i]){
				s = currentscenes;
				s[i]++;
				total+=combinations(s);
			}
			checked = true;
		}
	}
	if (!checked){
		return map[currentscenes]=1;
	}
	return map[currentscenes]=total;
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	int temp;
	std::vector<int> currentscenes;
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		scenes.push_back(temp);
		currentscenes.push_back(0);
	}
	std::cout<<combinations(currentscenes)<<std::endl;
	return 0;
}