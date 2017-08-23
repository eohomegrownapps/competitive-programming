#include <iostream>
int main(int argc, char const *argv[])
{
	long long food, buddies;
	std::cin>>food>>buddies;
	long long dividedamount = (food-(food%(buddies+1)))/(buddies+1);
	long long givetobuddies = dividedamount;
	long long givetoself = dividedamount+(food%(buddies+1));
	std::cout<<givetobuddies<<" "<<givetoself<<std::endl;
	return 0;
}
