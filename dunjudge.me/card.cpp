#include <iostream>
#include <queue>

int main(int argc, char const *argv[])
{
	long m,k;
	std::cin>>m>>k;
	std::deque<long> d;
	for (long i = 0; i<m; i++){
		d.push_back(i);
	}
	char temp;
	std::cin>>temp;
	while (temp!='.'){
		if (temp=='A'){
			long l = d.front();
			d.pop_front();
			d.push_back(l);
		} else {
			long a = d[0];
			long b = d[1];
			d.pop_front();
			d.pop_front();
			d.push_front(a);
			d.push_back(b);
		}
		std::cin>>temp;
	}
	std::cout<<d[k-1]<<" "<<d[k]<<" "<<d[k+1]<<std::endl;
	return 0;
}