#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

bool test(std::vector<int> v){
	int length = v.size();
	int maxinstack = 0;
	int number = 0;
	std::stack<int> stac;
	for (int i = 0; i<v.size(); i++){
		if (v[i]>maxinstack){
			while (stac.size()==0||stac.top()!=v[i]){
				maxinstack++;
				number++;
				stac.push(number);
			}
			stac.pop();
			if (stac.size()==0){
				maxinstack = 0;
			} else {
				maxinstack = stac.top();
			}
		} else if (stac.top()==v[i]){
			stac.pop();
			if (stac.size()==0){
				maxinstack = 0;
			} else {
				maxinstack = stac.top();
			}
		} else {
			return false;
		}
	}
	if (stac.size()==0){
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	while (n!=0){
		int a;
		std::vector<int> v;
		std::cin>>a;
		while (a!=0){
			v.push_back(a);
			int temp;
			for (int i = 0; i<n-1; i++){
				std::cin>>temp;
				v.push_back(temp);
			}
			bool y = test(v);
			if (y){
				std::cout<<"Yes"<<std::endl;
			} else {
				std::cout<<"No"<<std::endl;
			}
			std::cin>>a;
			v.clear();
		}
		std::cout<<std::endl;
		std::cin>>n;
	}
	return 0;
}