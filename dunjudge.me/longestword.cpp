#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string str, max;
	max = "";
	int num;
	std::cin>>num;
	for (int i = 0; i<num; i++){
		std::cin>>str;
		if (str.length()>max.length()){
			max = str;
		}
	}
	std::cout<<max<<std::endl;
	return 0;
}