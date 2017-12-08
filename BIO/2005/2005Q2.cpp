#include <iostream>
#include <vector>

std::vector<int> parseRule(std::string rule){
	char x = rule[0];
	int w = x-'0';
	int d = 0;
	if (rule[1]=='R'){
		d = 1;
	}
	char y = rule[2];
	int t = y-'0';
	std::vector<int> v;
	v.push_back(w);
	v.push_back(d);
	v.push_back(t);
	return v;
}

int main(int argc, char const *argv[])
{
	std::vector<int> machine;
	machine.resize(2000020);
	std::vector<std::vector<std::vector<int> > > states;
	int n;
	std::cin>>n;
	std::vector<int> z;
	std::vector<std::vector<int> > y;
	y.push_back(z);
	states.push_back(y);
	for (int i = 0; i<n; i++){
		std::string x;
		std::cin>>x;
		std::vector<int> rulea = parseRule(x);
		std::string y;
		std::cin>>y;
		std::vector<int> ruleb = parseRule(y);
		std::vector<std::vector<int> > rules;
		rules.push_back(rulea);
		rules.push_back(ruleb);
		states.push_back(rules);
	}
	long iterations;
	std::cin>>iterations;
	/*for (std::vector<std::vector<int> > a : states){
		std::cout<<"state"<<std::endl;
		for (std::vector<int> b : a){
			std::cout<<"case"<<std::endl;
			for (int c : b){
				std::cout<<c<<std::endl;
			}
		}
	}*/
	long pointer = 1000010;
	int state = 1;
	for (long j = 0; j<iterations; j++){
		if (state==0){
			for (long k = pointer-3; k<pointer+4; k++){
				std::cout<<machine[k];
			}
			std::cout<<std::endl<<j<<std::endl;
			return 0;
		}
		int currentCell = machine[pointer];
		int digitToWrite = states[state][currentCell][0];
		int direction = states[state][currentCell][1];
		int s = states[state][currentCell][2];
		machine[pointer] = digitToWrite;
		if (direction){
			pointer++;
		} else {
			pointer--;
		}
		state = s;
	}
	for (long k = pointer-3; k<pointer+4; k++){
		std::cout<<machine[k];
	}
	std::cout<<std::endl<<iterations<<std::endl;
	return 0;
}