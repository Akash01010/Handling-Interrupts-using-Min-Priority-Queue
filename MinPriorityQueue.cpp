#include <iostream>
#include "MinPriorityQueue.hpp"

int main(){
	
	MinPriorityQueue<int> H;
	LinearList<int> Arr;
int *t;

	int size,val;
	int ch,key;

	do{
		std::cout << "SELECT AN OPERATION\n\n1. Insert an element\n2. Get the minimum element\n3. Remove the minimum element\n4. Check whether the heap is empty or not\n5. Size of the heap\n6. Exit\n\nEnter your choice : ";
		std::cin >> ch;

		switch(ch){
			case 1:
					std::cout << "Enter the key : ";
					std::cin >> key;
					H.insert(key,0,0,0);
					break;
			case 2:
					std::cout << "Minimum element is: " << H.minimum() << "\n";	
					break;
			case 3:
t =H.extract_min();
					std::cout << "Minimum element is: " << t[3] << "\n";
					break;
			case 4:
					if(H.empty())
						std::cout << "True\n";
					
					else 
						std::cout << "False\n";
					break;
			case 5:
					std::cout << "Size of the heap is : " << H.heap_size_() << "\n";		
					break;
			
		
		}if(ch == 6)break;	

	}while(ch<7);

	return 0;
}
