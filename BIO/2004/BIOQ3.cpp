#include <iostream>
#include <string>
#include <vector>
#include <map>

std::map<std::pair<int,int>, std::vector<std::vector<int> > > map;

std::vector<std::vector<int> > partition(int n, int r){
	//if (map.count(std::make_pair(n,r))>0){
	//	return map[std::make_pair(n,r)];
	//}
	if (r==0){
		std::vector<std::vector<int> > v;
		std::vector<int> nv;
		nv.push_back(n);
		v.push_back(nv);
		map.insert(std::make_pair(std::make_pair(n,r),v));
		return v;
	}
	std::vector<std::vector<int> > temp;
	for (int i = 1; i<n-r+1; i++){
		std::vector<std::vector<int> > tlis = partition(n-i,r-1);
		for (std::vector<int> abc : tlis){
			abc.push_back(i);
			temp.push_back(abc);
		}
	}
	map.insert(std::make_pair(std::make_pair(n,r),temp));
	return temp;
}

int main(int argc, char const *argv[])
{
	std::string temp;
	std::cin>>temp;
	int size = temp.size();
	std::string chars[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	std::string disallowed[4] = {"..--",".-.-","---.","----"};
	std::string code = "";
	for (char x : temp){
		int c = x-'a';
		code+=chars[c];
	}
	//std::cin>>size;
	std::vector<std::vector<int> > partitions = partition(code.size(),size-1);
	int count = 0;
	for (std::vector<int> v : partitions){
		bool tooLarge = false;
		int arrcounter = 0;
		for (int i : v){
			if (i>4){
				tooLarge = true;
				break;
			} else if (i==4){
				std::string substr = code.substr(arrcounter,4);
				bool disCheck = false;
				for (int a = 0; a<4; a++){
					if (disallowed[a]==substr){
						disCheck = true;
						break;
					}
				}
				if (disCheck){
					tooLarge=true;
					break;
				}
			}
			arrcounter+=i;
		}
		if (!tooLarge){
			count++;
		}
	}
	std::cout<<count<<std::endl;
	return 0;
}