#include <iostream>
#include <queue>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	while (n!=0){
		if (n==1){
			std::cout<<"Discarded cards:"<<std::endl;
			std::cout<<"Remaining card: "<<1<<std::endl;
		} else {
			std::queue<int> de;
			for (int i = 1; i<=n; i++){
				de.push(i);
			}
			std::cout<<"Discarded cards: ";
			while (de.size()>2){
				std::cout<<de.front()<<", ";
				de.pop();
				de.push(de.front());
				de.pop();
			}
			std::cout<<de.front()<<std::endl;
			de.pop();
			std::cout<<"Remaining card: "<<de.front()<<std::endl;
		}
		std::cin>>n;
	}
	return 0;
}