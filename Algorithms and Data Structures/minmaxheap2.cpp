#include <stdexcept>
#include <vector>
#include <iostream>
#include <map>

//left: 2*k right: 2*k+1 parent: k/2

class Heap {
		std::vector<long> minheap;
		std::vector<long> maxheap;
		std::map<long, long> min2max;
		std::map<long, long> max2min;
		void percolateDownMax(long index);
		void percolateDownMin(long index);
		void percolateUpMax(long index);
		void percolateUpMin(long index);
		void mapPair(long max, long min);
		void swapElements(long a, long b, bool min);
		long compareTriangleMax(long a, long b, long c);
		long compareTriangleMin(long a, long b, long c);
	public:
		Heap();
		long getMax();
		long deleteMax();
		long getMin();
		long deleteMin();
		void insert(long n);
		void view();
		std::vector<long> sort();
};

void Heap::percolateDownMax(long index){
	while (true){
		if (2*index+1>maxheap.size()){
			return;
		}
		long triindex = Heap::compareTriangleMax(index, 2*index, 2*index+1);
		if (triindex==index){
			return;
		} else {
			Heap::swapElements(index,triindex, false);
			index = triindex;
		}
	}
}

void Heap::percolateDownMin(long index){
	while (true){
		if (2*index+1>minheap.size()){
			return;
		}
		long triindex = Heap::compareTriangleMin(index, 2*index, 2*index+1);
		if (triindex==index){
			return;
		} else {
			Heap::swapElements(index,triindex, true);
			index = triindex;
		}
	}
}

void Heap::percolateUpMax(long index){
	while (index!=1){
		long parent = index/2;
		if (maxheap[index]>maxheap[parent]){
			Heap::swapElements(index,parent,false);
			index = parent;
		} else {
			return;
		}
	}
}

void Heap::percolateUpMin(long index){
	while (index!=1){
		long parent = index/2;
		if (minheap[index]<minheap[parent]){
			Heap::swapElements(index,parent,true);
			index = parent;
		} else {
			return;
		}
	}
}

void Heap::mapPair(long min, long max){
	max2min[max] = min;
	min2max[min] = max;
}

void Heap::swapElements(long a, long b, bool min){
	if (min==true){
		long temp = minheap[a];
		minheap[a] = minheap[b];
		minheap[b] = temp;
		a1 = min2max[a];
		b1 = min2max[b];
		Heap::mapPair(a,b1);
		Heap::mapPair(b,a1);
	} else {
		long temp = maxheap[a];
		maxheap[a] = maxheap[b];
		maxheap[b] = temp;
		a1 = max2min[a];
		b1 = max2min[b];
		Heap::mapPair(b1,a);
		Heap::mapPair(a1,b);
	}
}

long Heap::compareTriangleMax(long a, long b, long c){
	long maxindex = a;
	if (heap[b]>heap[a]){
		maxindex = b;
	}
	if (heap[c]>heap[maxindex]){
		maxindex = c;
	}
	return maxindex;
}

long Heap::compareTriangleMin(long a, long b, long c){
	long maxindex = a;
	if (heap[b]<heap[a]){
		maxindex = b;
	}
	if (heap[c]<heap[maxindex]){
		maxindex = c;
	}
	return maxindex;
}

Heap::Heap(){
	heap.push_back(0);
}

long Heap::getMax(){
	if (heap.size()<=1){
		throw std::invalid_argument("Heap Empty");
	}
	return heap[1];
}

long Heap::deleteMax(){
	if (heap.size()<=1){
		throw std::invalid_argument("Heap Empty");
	}
	long ret = heap[1];
	heap[1]=heap.back();
	heap.pop_back();
	Heap::percolateDown(1);
	return ret;
}

void Heap::insert(long n){
	minheap.push_back(n);
	maxheap.push_back(n);
	Heap::mapPair(minheap.size()-1,maxheap.size()-1);
	Heap::percolateUpMin(minheap.size()-1);
	Heap::percolateUpMax(maxheap.size()-1);
}
/*
std::vector<long> Heap::sort(){
	std::vector<long> n;
	while (heap.size()>1){
		n.push_back(Heap::deleteMax());
	}
	return n;
}

void Heap::view(){
	for (auto i=heap.begin(); i!=heap.end(); ++i){
		std::cout << *i << ' ';
	}
	std::cout<<std::endl;
}
*/
int main(int argc, char const *argv[])
{
	char c;
	long s;
	Heap h;
	while (true){
		std::cin>>c;
		switch(c){
			case 'g': std::cout<<h.getMax()<<std::endl; break;
			case 'd': std::cout<<h.deleteMax()<<std::endl; break;
			case 'i': long n; std::cin>>n; h.insert(n); break;
			case 's': std::vector<long> v = h.sort(); for (auto i=v.begin(); i!=v.end(); ++i){std::cout << *i << ' ';} std::cout<<std::endl; break;
		}
		h.view();
	}
	return 0;
}