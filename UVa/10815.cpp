#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>

int main(int argc, char const *argv[])
{
	std::set<std::string> s;
	std::string word = "";
	char c;
	while (!std::cin.eof()){
		std::cin>>std::noskipws>>c;
		//std::cout<<c<<std::endl;
		if (std::isalpha(c)){
			word+=std::tolower(c);
		} else {
			if (word.size()>0){
				s.insert(word);
				word="";
			}
		}
	}
	if (word.size()>0){
		s.insert(word);
		word="";
	}
	for (std::string st : s){
		std::cout<<st<<std::endl;
	}
	return 0;
}