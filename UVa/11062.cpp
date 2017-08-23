#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>

int main(int argc, char const *argv[])
{
	std::set<std::string> s;
	std::string word = "";
	char c;
	bool hyphen = false;
	while (!std::cin.eof()){
		std::cin>>std::noskipws>>c;
		//std::cout<<c<<std::endl;
		if (hyphen==true){
			if (c=='\n'){
				word.pop_back();
			} else if (!std::isalpha(c)){
				s.insert(word);
				word="";
			} else {
				word+=std::tolower(c);
			}
			hyphen = false;
		} else {
			hyphen = false;
			if (std::isalpha(c)){
				word+=std::tolower(c);
			} else {
				if (c=='-'){
					word+=c;
					hyphen = true;
				} else if (word.size()>0){
					s.insert(word);
					word="";
					hyphen = false;
				}
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