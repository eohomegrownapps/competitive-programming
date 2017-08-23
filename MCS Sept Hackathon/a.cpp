#include <iostream>
#include <vector>

int wall(std::vector<int> stacks){
	int height = 0;
	for (int h = 0; h<stacks.size(); h++){
		height += stacks[h];
	}
	height = height/stacks.size();
	int sum = 0;
	for (int i = 0; i<stacks.size(); i++){
		if (stacks[i]>height){
			sum += (stacks[i]-height);
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int n,a;
	std::vector<int> v;
	int temp;
	std::cin>>n;
	int counter = 0;
	while (n!=0){
		counter++;
		for (a = 0; a<n; a++){
			std::cin>>temp;
			v.push_back(temp);
		}
		std::cout<<"Set #"<<counter<<std::endl;
		std::cout<<"The minimum number of moves is "<<wall(v)<<"."<<std::endl;
		v.clear();
		std::cin>>n;
	}
	return 0;
}
