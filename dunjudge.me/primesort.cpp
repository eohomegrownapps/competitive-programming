#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
std::vector<long> originals;
std::vector<int> primefactorise (long num, std::vector<int> pfs = std::vector<int>()){
	//just use primefactorise(long) and it will give you a sorted list of PFs
	long double sqrt = std::sqrt(num);
	if (num==1){
		return pfs;
	}
	for (int i = 2; i<sqrt+1; i++){
		if (num%i==0){
			pfs.push_back(i);
			return primefactorise(num/i, pfs);
		}
	}
	pfs.push_back(num);
	return pfs;
}

bool sortf(std::vector<int> i, std::vector<int> j){
	if (i.size()==1&&j.size()==1){
		if (originals[i[0]]>originals[j[0]]){
			return false;
		}
		return true;
	}
	if (i.size()==1){
		if (originals[i[0]]>j[1]){
			return false;
		}
		return true;
	}
	if (j.size()==1){
		if (i[1]>originals[j[0]]){
			return false;
		}
		return true;
	}
	int size;
	int first = true;
	if (i.size()>j.size()){
		size = j.size();
		first = false;
	} else {
		size = i.size();
	}
	for (int k = 1; k<size; k++){
		if (i[k]<j[k]){
			return true;
		} 
		if (i[k]>j[k]){
			return false;
		}
	}
	return first;
}

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int> > v;
	std::vector<int> tempv;
	int n;
	std::cin>>n;
	long temp;
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		tempv = primefactorise(temp);
		tempv.insert(tempv.begin(),i);
		v.push_back(tempv);
		originals.push_back(temp);
	}
	std::sort(v.begin(), v.end(),sortf);
	for (int j = 0; j<v.size(); j++){
		std::cout<<originals[v[j][0]]<<std::endl;
	}
	return 0;
}