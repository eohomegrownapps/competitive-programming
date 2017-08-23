#include <iostream>
#include <stack>
#include <queue>

bool inStack(std::stack<int> &s, int x){
	try{
		s.push(x);
	} catch (...){
		return false;
	}
	return true;
}

bool outStack(std::stack<int> &s, int x){
	if (s.size()==0){
		return false;
	}
	try{
		int top = s.top();
		s.pop();
		if (top==x){
			return true;
		}
		return false;
	} catch (...){
		return false;
	}
}

bool inQueue(std::queue<int> &s, int x){
	try{
		s.push(x);
	} catch (...){
		return false;
	}
	return true;
}

bool outQueue(std::queue<int> &s, int x){
	if (s.size()==0){
		return false;
	}
	try{
		int top = s.front();
		s.pop();
		if (top==x){
			return true;
		}
		return false;
	} catch (...){
		return false;
	}
}

bool inPriorityQueue(std::priority_queue<int> &s, int x){
	try{
		s.push(x);
	} catch (...){
		return false;
	}
	return true;
}

bool outPriorityQueue(std::priority_queue<int> &s, int x){
	if (s.size()==0){
		return false;
	}
	try{
		int top = s.top();
		s.pop();
		if (top==x){
			return true;
		}
		return false;
	} catch (...){
		return false;
	}
}

int main(int argc, char const *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)){
		bool p = true;
		bool s = true;
		bool q = true;
		std::stack<int> st;
		std::queue<int> qu;
		std::priority_queue<int> pr;
		int n;
		try {
			n = std::stoi(line);
		} catch(...){
			return 0;
		}
		for (int i = 0; i<n; i++){
			int a,x;
			std::cin>>a>>x;
			if (a==1){
				if (q){
					q = inQueue(qu,x);
				}
				if (s){
					s = inStack(st,x);
				}
				if (p){
					p = inPriorityQueue(pr,x);
				}
			} else {
				if (q){
					q = outQueue(qu,x);
				}
				if (s){
					s = outStack(st,x);
				}
				if (p){
					p = outPriorityQueue(pr,x);
				}
			}
		}
		if (p&&!q&&!s){
			std::cout<<"priority queue"<<std::endl;
		} else if (!p&&q&&!s){
			std::cout<<"queue"<<std::endl;
		} else if (!p&&!q&&s){
			std::cout<<"stack"<<std::endl;
		} else if (!p&&!q&&!s){
			std::cout<<"impossible"<<std::endl;
		} else {
			std::cout<<"not sure"<<std::endl;
		}
		//std::cout<<p<<q<<s<<std::endl;
		std::getline(std::cin, line);
	}
	return 0;
}