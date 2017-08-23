#include <iostream>
#include <vector>
#include <string>
char colours[3] = {'R','G','B'};

char triangle(std::vector<std::vector<char> > v){
	int pointer = v.size()-1;
	for (int i = 1; i<v.size(); i++){
		for (int j = 0; j<pointer; j++){
			if (v[i-1][j]==v[i-1][j+1]){
				v[i][j]=v[i-1][j];
			} else {
				for (int k = 0; k<3; k++){
					if (colours[k]!=v[i-1][j]&&colours[k]!=v[i-1][j+1]){
						v[i][j]=colours[k];
						break;
					}
				}
			}
		}
		pointer--;
	}
	return v[v.size()-1][0];
}

int main(int argc, char const *argv[])
{
	std::cout<<"Euan Ong"<<std::endl;
	std::cout<<"Magdalen College School"<<std::endl;
	std::string str;
	std::cin>>str;
	std::vector<std::vector<char> > v;
	std::vector<char> temp;
	for (int i = 0; i<str.length(); i++){
		temp.push_back((char)str[i]);
	}
	v.push_back(temp);
	temp.clear();
	for (int i = 0; i<str.length(); i++){
		temp.push_back('.');
	}
	for (int i = 1; i<str.length(); i++){
		v.push_back(temp);
	}
	std::cout<<triangle(v)<<std::endl;
	return 0;
}