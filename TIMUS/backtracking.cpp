#include <vector>
#include <iostream>
int ans = 0;

bool reject(std::vector<int> vec, int sum, int size){
	int su = 0;
	if (vec.size()==(size/2)){
		return false;
	}
	if (vec.size()>(size/2)){
		return true;
	}
	for (int i = 0; i<vec.size(); i++){
		su += vec[i];
	}
	if (su>sum|su+(9*((size/2)-vec.size()))<sum){
		return true;
	}
	return false;
}

bool accept(std::vector<int> vec, int sum, int size){
	int su = 0;
	for (int i = 0; i<vec.size(); i++){
		su += vec[i];
	}
	if (vec.size()==size/2&&su==sum){
		return true;
	}
	return false;
}
std::vector<int> first(std::vector<int> vec, int size){
	std::vector<int> v;
	v.push_back(-1);
	if (vec.size()==size/2){
		return v;
	}
	vec.push_back(0);
	return vec;
}

std::vector<int> next(std::vector<int> vec){
	std::vector<int> v;
	v.push_back(-1);
	if (vec[vec.size()-1] != 9){
		vec[vec.size()-1]+=1;
		return vec;
	} else{
		return v;
	}
}

void backtrack(std::vector<int> instance, int sum, int size){
	std::vector<int> v;
	v.push_back(-1);
	if (reject(instance, sum, size)){
		return;
	}
	if (accept(instance, sum, size)){
		ans += 1;
	}
	std::vector<int> f = first(instance, size);
	while (f != v){
		backtrack(f, sum, size);
		f = next(f);
	}

} 

int main(int argc, char const *argv[])
{
	std::vector<int> ve;
	long total;
	for (int i = 0; i<9*4+1; i++){
		ans = 0;
		backtrack(ve,i,8);
		ans = ans*ans;
		std::cout<<ans<<std::endl;
		total += ans;
	}
	std::cout<<total<<std::endl;
	return 0;
}