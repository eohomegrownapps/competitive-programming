#include <queue>
#include <vector>
#include <iostream>
#include <utility>

class ComparisonClass {
public:
	bool operator() (std::pair<long, std::pair<long, long> > b, std::pair<long, std::pair<long, long> > a) {
		if (a.second.first==b.second.first){
			if (a.first<b.first){
				return true;
			} else {
				return false;
			}
		} else if (a.second.first<b.second.first){
			return true;
		} else {
			return false;
		}
	}
};

int main(int argc, char const *argv[])
{
	std::string temp;
	long id, time;
	std::cin>>temp;
	std::priority_queue<std::pair<long, long>, std::vector<std::pair<long, std::pair<long, long> > >, ComparisonClass> pq;
	std::pair<long, std::pair<long, long> > t;
	std::pair<long, long> u;
	//first is renew time, second is add time
	while (temp!="#"){
		std::cin>>id>>time>>temp;
		u = std::make_pair(time, time);
		t = std::make_pair(id,u);
		pq.push(t);
	}
	long k;
	std::cin>>k;
	for (long i = 0; i<k; i++){
		std::pair<long, std::pair<long, long> > f = pq.top();
		pq.pop();
		std::cout<<f.first<<std::endl;
		f.second.first+=f.second.second;
		pq.push(f);
	}
	return 0;
}