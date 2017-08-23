#include <iostream>
#include <vector>

bool jugmatch(std::vector<int> a, std::vector<int> b){
	for (int i = 0; i<a.size(); i++){
		if (a[i]!=b[i]){
			return false;
		}
	}
	return true;
}

bool isInUnvisited(std::vector<int> a, std::vector<std::vector<int> > visited){
	for (int i = 0; i<visited.size(); i++){
		if (jugmatch(a,visited[i])==true){
			return true;
		}
	}
	return false;
}

std::vector<int> jugpour(int fulla, int a, int b){
	a = a+b;
	b=0;
	int diff = a-fulla;
	if (diff>0){
		a = fulla;
		b = diff;
	}
	std::vector<int> v;
	v.push_back(b);
	v.push_back(a);
	return v;
}

std::vector<std::vector<int> > jugpossibilities(std::vector<int> full, std::vector<int> v, std::vector<std::vector<int> > visited){
	std::vector<std::vector<int> > temp;
	std::vector<int> tempv;
	for (int i = 0; i<v.size(); i++){
		tempv = v;
		tempv[i] = 0;
		temp.push_back(tempv);
		tempv = v;
		tempv[i] = full[i];
		temp.push_back(tempv);
	}
	if (v.size()==2){
		tempv = jugpour(full[1],v[1],v[0]);
		if (tempv[0]!=-1){
			std::reverse(tempv.begin(), tempv.end());
			temp.push_back(tempv);
		}
		tempv = jugpour(full[0],v[0],v[1]);
		if (tempv[0]!=-1){
			std::reverse(tempv.begin(), tempv.end());
			temp.push_back(tempv);
		}
	}
	std::vector<int> tv;
	if (v.size()==3){
		tv = jugpour(full[1],v[1],v[0]);
		if (tv[0]!=-1){
			tempv.clear();
			tempv.push_back(tv[1]);
			tempv.push_back(tv[0]);
			tempv.push_back(v[2]);
			temp.push_back(tempv);
		}
		tv = jugpour(full[2],v[2],v[0]);
		if (tv[0]!=-1){
			tempv.clear();
			tempv.push_back(tv[1]);
			tempv.push_back(v[1]);
			tempv.push_back(tv[0]);
			temp.push_back(tempv);
		}
		tv = jugpour(full[0],v[0],v[1]);
		if (tv[0]!=-1){
			tempv.clear();
			tempv.push_back(tv[0]);
			tempv.push_back(tv[1]);
			tempv.push_back(v[2]);
			temp.push_back(tempv);
		}
		tv = jugpour(full[2],v[2],v[1]);
		if (tv[0]!=-1){
			tempv.clear();
			tempv.push_back(v[0]);
			tempv.push_back(tv[2]);
			tempv.push_back(tv[1]);
			temp.push_back(tempv);
		}
		tv = jugpour(full[0],v[0],v[2]);
		if (tv[0]!=-1){
			tempv.clear();
			tempv.push_back(tv[1]);
			tempv.push_back(v[1]);
			tempv.push_back(tv[0]);
			temp.push_back(tempv);
		}
		tv = jugpour(full[1],v[1],v[2]);
		if (tv[0]!=-1){
			tempv.clear();
			tempv.push_back(v[0]);
			tempv.push_back(tv[1]);
			tempv.push_back(tv[0]);
			temp.push_back(tempv);
		}
	}
	std::vector<std::vector<int> > final;
	for (int j = 0; j<temp.size(); j++){
		std::cout<<"a"<<temp[j][0]<<" "<<temp[j][1]<<std::endl;
		if (isInUnvisited(temp[j],visited)==false){
			final.push_back(temp[j]);
		}
	}
	return final;
}

int jugsearch(std::vector<int> full, int quantity){
	std::vector<std::vector<int> > currentjugs;
	std::vector<std::vector<int> > newcurrentjugs;
	bool two;
	std::vector<int> twov(2);
	if (full.size()==2){
		two = true;
		twov[0] = 0;
		twov[1] = 0;
		currentjugs.push_back(twov);
	} else {
		two = false;
		twov[0] = 0;
		twov[1] = 0;
		twov[2] = 0;
		currentjugs.push_back(twov);
	}
	bool found = false;
	int distance = 0;
	std::vector<std::vector<int> > visited;
	visited.push_back(twov);
	std::vector<std::vector<int> > tempvisited;
	while (found == false){
		std::cout<<std::endl;
		for (std::vector<int> v : currentjugs){
			std::cout<<v[0]<<" "<<v[1]<<std::endl;
			tempvisited = jugpossibilities(full, v, visited);
			for (std::vector<int> u : tempvisited){
				for (int k = 0; k<u.size(); k++){
					if (u[k]==quantity){
						return distance+1;
					}
				}
				newcurrentjugs.push_back(u);
				visited.push_back(u);
			}
		}
		currentjugs = newcurrentjugs;
		newcurrentjugs.clear();
		distance++;
	}
}

int main(int argc, char const *argv[])
{
	int j,n;
	std::cin>>j>>n;
	int temp;
	std::vector<int> full;
	for (int i = 0; i<j; i++){
		std::cin>>temp;
		full.push_back(temp);
	}
	if (n==0){
		std::cout<<0<<std::endl;
		return 0;
	}
	if (j==1){
		if (n==j){
			std::cout<<1<<std::endl;
			return 0;
		}
	}
	std::cout<<jugsearch(full,n)<<std::endl;
	return 0;
}