#include <iostream>
#include <queue>
#include <set>

void permutations(std::string &s, std::set<std::string> &visited, std::queue<std::string> &q){
	//std::cout<<"-"<<std::endl;
	std::string str1, str2, str3, str4;
	//std::cout<<"-"<<std::endl;
	str1="";str1.push_back(s[1]);str1.push_back(s[2]);str1.push_back(s[3]);str1.push_back(s[0]);str1.push_back(s[4]);str1.push_back(s[5]);str1.push_back(s[6]);
	str2="";str2.push_back(s[3]);str2.push_back(s[0]);str2.push_back(s[1]);str2.push_back(s[2]);str2.push_back(s[4]);str2.push_back(s[5]);str2.push_back(s[6]);
	str3="";str3.push_back(s[0]);str3.push_back(s[1]);str3.push_back(s[2]);str3.push_back(s[4]);str3.push_back(s[5]);str3.push_back(s[6]);str3.push_back(s[3]);
	str4="";str4.push_back(s[0]);str4.push_back(s[1]);str4.push_back(s[2]);str4.push_back(s[6]);str4.push_back(s[3]);str4.push_back(s[4]);str4.push_back(s[5]);
	//std::cout<<"-"<<std::endl;
	q.push(str1);q.push(str2);q.push(str3);q.push(str4);
	//std::cout<<"-"<<std::endl;
	visited.insert(str1);visited.insert(str2);visited.insert(str3);visited.insert(str4);
}

int bfs(std::string ans){
	std::string initial = "1234567";
	if (ans==initial){
		return 0;
	}
	std::set<std::string> visited;
	visited.insert("1234567");
	std::queue<std::string> q;
	permutations(initial,visited,q);
	q.push("-1");
	int distance = 1;
	while (true){
		std::string x = q.front();
		q.pop();
		if (x=="-1"){
			distance++;
			q.push("-1");
		} else if (x==ans){
			return distance;
		} else  {
			permutations(x,visited,q);
		}
	}
}

int main(int argc, char const *argv[])
{
	std::string test;
	std::cin>>test;
	std::cout<<bfs(test)<<std::endl;
	return 0;
}