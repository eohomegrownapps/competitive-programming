#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	int s = 0;
	int p = 0;
	for (int i = 0; i<n; i++){
		int a,b,ans;
		char op;
		char eq;
		std::cin>>a>>op>>b>>eq>>ans;
		if (op=='+'){
			if (a+b==ans){
				s++;
			}
		} else {
			if (a-b==ans){
				s++;
			}
		}
	}
	for (int i = 0; i<n; i++){
		int a,b,ans;
		char op;
		char eq;
		std::cin>>a>>op>>b>>eq>>ans;
		if (op=='+'){
			if (a+b==ans){
				p++;
			}
		} else {
			if (a-b==ans){
				p++;
			}
		}
	}
	std::cout<<"Spongebob: "<<s<<std::endl;
	std::cout<<"Patrick: "<<p<<std::endl;
	return 0;
}