#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
	std::map<char, int> mapalp;
	char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for (int i = 0; i<26; i++){
		mapalp[alpha[i]]=0;
	}
	int m;
	std::cin>>m;
	char x;
	for (int j = 0; j<m; j++){
		std::cin>>x;
		mapalp[x]++;
	}
	for (int k = 0; k<26; k++){
		std::cout<<alpha[k]<<" "<<mapalp[alpha[k]]<<std::endl;
	}
	return 0;
}