#include <stdexcept>
#include <vector>
#include <iostream>

//left: 2*k right: 2*k+1 parent: k/2

class Heap {
		std::vector<long> heap;
		void percolateDown(long index);
		void percolateUp(long index);
		void swapElements(long a, long b);
		long compareTriangle(long a, long b, long c);
	public:
		Heap();
		long getMax();
		long deleteMax();
		void insert(long n);
		void view();
		std::vector<long> sort();
};

void Heap::percolateDown(long index){
	while (true){
		if (2*index+1>heap.size()){
			return;
		}
		long triindex = Heap::compareTriangle(index, 2*index, 2*index+1);
		if (triindex==index){
			return;
		} else {
			Heap::swapElements(index,triindex);
			index = triindex;
		}
	}
}

void Heap::percolateUp(long index){
	while (index!=1){
		long parent = index/2;
		if (heap[index]>heap[parent]){
			Heap::swapElements(index,parent);
			index = parent;
		} else {
			return;
		}
	}
}

void Heap::swapElements(long a, long b){
	long temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

long Heap::compareTriangle(long a, long b, long c){
	long maxindex = a;
	if (heap[b]>heap[a]){
		maxindex = b;
	}
	if (heap[c]>heap[maxindex]){
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
	heap.push_back(n);
	Heap::percolateUp(heap.size()-1);
}

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