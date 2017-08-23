#include <vector>
#include <iostream>

std::vector<std::vector<int> > partitions(int n){
	std::vector<std::vector<std::vector<int> > > v;
	std::vector<std::vector<int> > temp;
	std::vector<int> tempv;
	tempv.push_back(1);
	temp.push_back(tempv);
	v.push_back(temp);
	for (int i = 1; i<n; i++){
		temp.clear();
		for (std::vector<int> tv : v[i-1]){
			tv[tv.size()-1]+=1;
			temp.push_back(tv);
			tv[tv.size()-1]-=1;
			tv.push_back(1);
			temp.push_back(tv);
		}
		v.push_back(temp);
	}
	return v[n-1];
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	std::vector<std::vector<int> > v = partitions(n);
	for (std::vector<int> tv : v){
		std::cout<<"---"<<std::endl;
		for (int t : tv){
			std::cout<<t<<std::endl;
		}
	}
	return 0;
}