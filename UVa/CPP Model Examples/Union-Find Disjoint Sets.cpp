#include <vector>

std::vector<int> pset(1000);
int numOfSets;

void initSet(int _size){
	pset.resize(_size);
	for (int i = 0; i<_size; i++){
		pset[i]=-1;
	}
}

int findSet(int i){
	if (pset[i]<0){
		return i;
	} else {
		return pset[i]=findSet(pset[i]);
	}
}

void unionSet(int i, int j){
	int a = findSet(i);
	int b = findSet(j);
	if (pset[a]<pset[b]){
		pset[b]=a;
	} else {
		pset[a]=b;
	}
	numOfSets--;
}

bool isSameSet(int i, int j){
	if (findSet(i)==findSet(j)){
		return true;
	}
	return false;
}

int numberOfSets(){
	return numOfSets;
}