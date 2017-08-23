#include <vector>
#include <algorithm>
#include <iostream>

bool descending(int i, int j){
	return i>j;
}

long time(int spheres, std::vector<int> times){
	std::sort(times.begin(), times.end(), descending);
	long duration = 0;
	for (int i = 0; i<times.size(); i++){
		if (i<spheres){
			duration+=times[i];
		} else {
			duration+=2*times[i];
		}
	}
	return duration;
}

int main(int argc, char const *argv[])
{
	int n,s;
	std::cin>>n>>s;
	int temp;
	std::vector<int> v;
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		v.push_back(temp);
	}
	std::cout<<time(s,v)<<std::endl;
	return 0;
}