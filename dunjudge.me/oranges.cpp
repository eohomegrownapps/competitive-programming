#include <iostream>

int main(int argc, char const *argv[])
{
	long n;
	std::cin>>n;
	long largest = -1;
	long indexoflargest = -1; 
	long nextlargest = -1;
	long indexofnextlargest = -1;
	long currentno = 0;
	for (int i = 1; i<n+1; i++){
		std::cin>>currentno;
		if (currentno>largest){
			indexofnextlargest = indexoflargest;
			nextlargest = largest;
			largest = currentno;
			indexoflargest = i;
		} else if (currentno>nextlargest){
			indexofnextlargest = i;
			nextlargest = currentno;
		}
	}
	if (indexofnextlargest>indexoflargest){
		std::cout<<indexoflargest<<" "<<indexofnextlargest<<std::endl;
	} else {
		std::cout<<indexofnextlargest<<" "<<indexoflargest<<std::endl;
	}
	return 0;
}