#include <iostream>
#include <vector>
#include <string>
#include <deque>

int main(int argc, char const *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)){
		if (line.size()==0){
			return 0;
		}
		std::vector<char> v;
		std::deque<char> de;
		bool pushback = true;
		//long count = 0;
		for (char x : line){
			if (x=='['){
				pushback = false;
				if (v.size()!=0){
					for (long i = v.size()-1; i>-1; i--){
						de.push_front(v[i]);
					}
				}
				v.clear();
			} else if (x==']'){
				pushback = true;
				if (v.size()!=0){
					for (long i = v.size()-1; i>-1; i--){
						de.push_front(v[i]);
					}
				}
				v.clear();
			} else if (pushback==true){
				de.push_back(x);
				//count++;
			} else {
				v.push_back(x);
				//count++;
			}
		}
		if (v.size()!=0){
			for (long i = v.size()-1; i>-1; i--){
				de.push_front(v[i]);
			}
		}
		while (de.size()>0){
			std::cout<<de.front();
			de.pop_front();
		}
		std::cout<<std::endl;
		//std::getline(std::cin, line);
	}
	return 0;
}