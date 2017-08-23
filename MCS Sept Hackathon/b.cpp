#include <iostream>
#include <vector>

int bubblesort(std::vector<long> arr){
	int count = 0;
	bool sorted = false;
	long swap;
	int i;
	while (sorted==false){
		sorted = true;
		for (i = 0; i<arr.size()-1; i++){
			if (arr[i] > arr[i+1]){
				sorted = false;
				count++;
				swap = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = swap;
			}
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n,i;
	std::cin>>n;
	long temp;
	std::vector<long> v;
	while (n!=0){
		for (i = 0; i<n; i++){
			std::cin>>temp;
			v.push_back(temp);
		}
		std::cout<<bubblesort(v)<<std::endl;
		v.clear();
		std::cin>>n;
	}
	return 0;
}