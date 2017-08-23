#include <iostream>
#include <list>
#include <vector>
#include <string>

long whichTeam(std::vector<std::vector<long> > &v, long x){
	for (long i = 0; i<v.size(); i++){
		for (long j = 0; j<v[i].size(); j++){
			if (v[i][j]==x){
				return i;
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	std::string line;
	long count = 1;
	long n;
	std::cin>>n;
	while (n!=0){
		std::cout<<"Scenario #"<<count<<std::endl;
		long a, temp;
		std::vector<std::vector<long> > teams;
		std::vector<std::list<long>::iterator> v;
		std::list<long> queue;
		for (long i = 0; i<n; i++){
			std::cin>>a;
			std::vector<long> team;
			for (long j = 0; j<a; j++){
				std::cin>>temp;
				team.push_back(temp);
			}
			teams.push_back(team);
			v.push_back(queue.end());
		}
		std::string command;
		std::cin>>command;
		while (command!="STOP"){
			if (command=="ENQUEUE"){
				long person;
				std::cin>>person;
				long team = whichTeam(teams,person);
				if (v[team]==queue.end()){
					queue.push_back(person);
					std::list <long>::iterator iter = queue.begin();
    				std::advance(iter, queue.size() - 1);
					v[team]=iter;
				} else {
					//std::advance(v[team],1);
					++v[team];
					queue.insert(v[team],person);
					--v[team];
				}
			} else if (command=="DEQUEUE"){
				if (!queue.empty()){
					long team = whichTeam(teams,queue.front());
					if (v[team]==queue.begin()){
						v[team]=queue.end();
					}
					std::cout<<queue.front()<<std::endl;
					queue.pop_front();
				}
			}
			//for (long i : queue){
			//	std::cout<<i<<std::endl;
			//}
			std::cin>>command;
		}
		count++;
		std::cout<<std::endl;
		std::cin>>n;
	}
	return 0;
}