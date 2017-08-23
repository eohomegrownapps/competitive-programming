#include <iostream>

int main(int argc, char const *argv[])
{
	int x, y;
	char op;
	std::cin>>x>>op>>y;
	if (op == '+'){
		std::cout<<x+y<<std::endl;
	} else if (op == '-'){
		std::cout<<x-y<<std::endl;
	} else if (op == '*'){
		std::cout<<x*y<<std::endl;
	}
	return 0;
}