#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
	std::vector<int> v;
	int n;
	std::cin>>n;
	int temp;
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		v.push_back(temp);
	}
	bool good = false;
	int iter;
	int switchn;
	while (good == false){
		good = true;
		for (iter = 0; iter < v.size()-1; iter++){
			if (v[iter]<v[iter+1]){
				good = false;
				switchn = v[iter];
				v[iter] = v[iter+1];
				v[iter+1] = switchn;
			}
		}
	}
	for (int j = 0; j<v.size()-1; j++){
		std::cout<<v[j]<<" ";
	}
	std::cout<<v[v.size()-1]<<std::endl;
	return 0;

}