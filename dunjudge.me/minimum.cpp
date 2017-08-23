int findMin(int N, int A[]){
	int min = A[0];
	for (int i = 1; i<N; i++){
		if (A[i]<min){
			min=A[i];
		}
	}
	return min;
}

#include <iostream>

int main(int argc, char const *argv[])
{
	int arr[] = {1,5,2,3,10};
	std::cout<<findMin(5,arr)<<std::endl;
	return 0;
}