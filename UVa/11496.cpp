#include <iostream>

bool checkUpwards(int a, int b){
	if (a<b){
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	while (n!=0){
		int peaks = 0;
		int temp;
		std::cin>>temp;
		int first = temp;

		int previous = temp;
		std::cin>>temp;
		int second = temp;
		bool upwards = checkUpwards(previous,temp);
		for (int i = 2; i<n; i++){
			previous = temp;
			std::cin>>temp;
			if (checkUpwards(previous,temp)!=upwards){
				peaks++;
				upwards = checkUpwards(previous,temp);
			}
		}
		previous = temp;
		temp = first;
		if (checkUpwards(previous,temp)!=upwards){
			peaks++;
			upwards = checkUpwards(previous,temp);
		}
		previous = temp;
		temp = second;
		if (checkUpwards(previous,temp)!=upwards){
			peaks++;
			upwards = checkUpwards(previous,temp);
		}
		std::cout<<peaks<<std::endl;
		std::cin>>n;
	}
	return 0;
}