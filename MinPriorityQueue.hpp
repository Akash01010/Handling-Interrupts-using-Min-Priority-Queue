// Purpose: IMPLEMENTING MIN PRORITY QUEUE
// Author: Akash Agrawal
// Date of Creation: April 22,2017
// Bugs: Not even a single (as usual ;) )

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
#include "seqLinearList.hpp"
#include <limits.h>

 //namespace cs202{
 	template<typename T>
 	class MinPriorityQueue{
 		// Private attributes and functions for class
 		// If you need any more functions / attributes
 		// define them yourself along with proper reasoning
 		// why they were introduced.
 		// DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
 		// YOU NEED TO USE THEM ALL.
 		// Primary container used in MinPriorityQueue

 		//LinearList<T> heap(100,INT_MAX);
 		LinearList<T> heap;
		T a[100][3];
		T*b;
 		int heap_size;
 		//swap 1D array
 		void swap_1d(int a, int b){
 			heap[a]+=heap[b];
			heap[b]=heap[a] - heap[b];
			heap[a]=heap[a] - heap[b];
			swap_2d(a,b);
			return;
 		}

 		//swap correspondingly 2d array
 		void swap_2d(int c,int b){
 			a[c][0]+=a[b][0];
 			a[b][0]=a[c][0]-a[b][0];
 			a[c][0]=a[c][0]-a[b][0];
 			a[c][1]+=a[b][1];
 			a[b][1]=a[c][1]-a[b][1];
 			a[c][1]=a[c][1]-a[b][1];
 			a[c][2]+=a[b][2];
 			a[b][2]=a[c][2]-a[b][2];
 			a[c][2]=a[c][2]-a[b][2];
 			return;
 		}

 		// heapifies the heap at position pos
 		void heapify(const int pos){//void heapify(const size_t& pos){
 			if (2*pos >heap_size && (2*pos+1) > heap_size )
 			{
 				return;
 			}
 			else if (2*pos <heap_size && (2*pos+1) > heap_size)
 			{
 				if (heap[2*pos]< heap[pos])
 				{
 					swap_1d(2*pos,pos);
 					return;
 				}
 				else{
 					return;
 				}
 			}
 			else{
	 			if (heap[2*pos] > heap[pos] && heap[2*pos + 1] >heap[pos])
	 			{
	 				return;
	 			}
	 			else if (heap[2*pos] > heap[2*pos +1])
	 			{
	 				swap_1d(2*pos +1,pos);
 					heapify(2*pos +1);
 					return;
	 			}
	 			else if (heap[2*pos] < heap[2*pos +1])
	 			{
	 				swap_1d(2*pos,pos);
 					heapify(2*pos);
 					return;
	 			}
	 			else{
	 				return;//when all the three keys are equal
	 			}
	 		}
 		};

 		// return the parent of an element
 		inline int parent(const int pos)//inline int parent(const size_t& pos);
 		{
 			return pos/2;
 		};

 		// return the left child of an element
 		inline int left_child(const int pos)//inline int left_child(const size_t& pos);
 		{
 			return 2*pos;
 		}

 		// return the right child of an element
 		inline int right_child(const int pos)//inline int right_child(const size_t& pos);
 		{
 			return 2*pos + 1;
 		};

 	public:
 		// default constructor
 		//MinPriorityQueue(int n){
		MinPriorityQueue(){
 			//heap.resize(n+1);
 			heap_size=INT_MAX;
 			//heap.push_back(heap_size);
			heap[0]=INT_MAX;
 			heap_size=0;
/*a=(T**)malloc((n+1)*sizeof(T*));
for(int k=0;k<=n;k++){
	a[k]=(T*)malloc(3*sizeof(T));
}*/

 		};//eisme ek to array m ek element by default daal do kayonki array 1 se shuru krni h

 		// construct a heap from the elements of a seqLinearList
 		MinPriorityQueue(const LinearList<T>& v){
 			/*LinearList<T> heap(100,INT_MAX);
 			int a[100][3];*/
 		};

 		// insert a value to the heap
 		void insert(const T a,T b,T c,T d){
 			/*if ((heap_size +1) == heap.capacity())
 			{
 			    heap_size=2*heap_size;
 				heap.resize(heap_size);
 			}*/
 			heap_size++;
 			heap[heap_size]=a;
			insert_2d(b,c,d);
 			heap_decrease_key(heap_size);
 		};

 		//special function for inserting other three values corresponding to the key
 		void insert_2d(int d,int b,int c){
 			a[heap_size][0]=d;
 			a[heap_size][1]=b;
 			a[heap_size][2]=c;
 			return;
 		};

 		// get the minimum element from the heap
 		inline T minimum(){
 			return heap[1];
 		};

 		// return the minimum element from the heap and remove it
 		// as well
 		T* extract_min(){
			if(heap_size==0){
	return NULL;
}
else{
			b=new T[4];
 			b[3]=heap[1];
 			heap[1]=heap[heap_size];
 			b[0]=a[1][0];
 			a[1][0]=a[heap_size][0];
 			b[1]=a[1][1];
 			a[1][1]=a[heap_size][1];
 			b[2]=a[1][2];
 			a[1][2]=a[heap_size][2];
 			heap_size--;
 			heapify(1);
 			return b;}
 		};

 		// return the heap size
 		inline int heap_size_(){
 			return heap_size;
 		};

 		// build a heap from elements of a seqLinearList container
 		void build_heap(const LinearList<T> v){
 			for (int i =(v.size())/2; i > 0; --i)
 			{
 				heapify(i);//
 			}
 		};

 		// check if MinPriorityQueue is empty
 		inline bool empty(){
 			return heap_size==0 ? true:false;
 		};

 		// heap_decrease_key function
 		void heap_decrease_key(const int pos){
 			int child=heap_size;
 			while(child/2 !=0 && heap[child] < heap[child/2]){
 				swap_1d(child,child/2);
 				child=child/2;
 			}
 			return;
 		};
 	};

#endif
