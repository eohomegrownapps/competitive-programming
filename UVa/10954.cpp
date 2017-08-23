#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	while (n!=0){
		long temp;
		std::priority_queue<long> q;
		for (int i = 0; i<n; i++){
			std::cin>>temp;
			q.push(-1*temp);
		}
		long total = 0;
		while (q.size()>1){
			long a = q.top();
			q.pop();
			long b = q.top();
			q.pop();
			total+=(-1*(a+b));
			q.push(a+b);
		}
		std::cout<<total<<std::endl;
		std::cin>>n;
	}
	return 0;
}