#include <vector>
#include <iostream>
#include <string>

std::vector<std::vector<int> > partitions(int n){
	std::vector<std::vector<std::vector<int> > > v;
	std::vector<std::vector<int> > temp;
	std::vector<int> tempv;
	tempv.push_back(1);
	temp.push_back(tempv);
	v.push_back(temp);
	for (int i = 1; i<n; i++){
		temp.clear();
		for (std::vector<int> tv : v[i-1]){
			tv[tv.size()-1]+=1;
			temp.push_back(tv);
			tv[tv.size()-1]-=1;
			tv.push_back(1);
			temp.push_back(tv);
		}
		v.push_back(temp);
	}
	return v[n-1];
}

int palindromes(std::string n){
	std::vector<std::vector<int> > v = partitions(n.length());
	std::string sub;
	int count;
	std::vector<std::string> temp;
	std::vector<std::string> rtemp;
	int palin = 0;
	for (std::vector<int> tv : v){
		temp.clear();
		count = 0;
		for (int t : tv){
			sub = n.substr(count, t);
			temp.push_back(sub);
			count += t;
		}
		rtemp = temp;
		std::reverse(rtemp.begin(), rtemp.end());
		bool correct = true;
		for (int i = 0; i<temp.size(); i++){
			if (temp[i]!=rtemp[i]){
				correct = false;
			}
		}
		if (correct==true){
			palin+=1;
		}
	}
	return palin-1;
}

int main(int argc, char const *argv[])
{
	std::string x;
	std::cin>>x;
	std::cout<<palindromes(x)<<std::endl;
	return 0;
}