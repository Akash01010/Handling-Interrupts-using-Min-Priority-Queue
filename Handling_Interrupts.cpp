#include <iostream>
#include "MinPriorityQueue.hpp"
#include <limits.h>

int main(int argc, char const *argv[])
{
	int counter=0,N,temp[4],i,count=0;
	int * t;
	std::cout<<"Enter the number of Routines(N given in problem)\n";
	std::cin>>N;
	MinPriorityQueue<int> mpq;
	int r[N+1][4];
	std::cout<<"\t\tEnter the ISR information:\n";
	for (i = 0; i < N; ++i)
	{
		std::cout<<"\nEnter the information of ISR "<<i<<"\n";
		std::cout<<"Device ID: ";
		std::cin>>r[i][0];
		std::cout<<"\nBurst Time(ms): ";
		std::cin>>r[i][1];
		std::cout<<"\nDelay(ms): ";
		std::cin>>r[i][2];
		std::cout<<"\nPriority Value: ";
		std::cin>>r[i][3];
	}
	r[i][0]=10000;
	r[i][1]=10000;
	r[i][2]=10000;
	r[i][3]=10;
	i=0;
	//mpq.insert(r[i][3]);
	temp[0]=r[i][0];
	temp[1]=r[i][1];
	temp[2]=r[i][2];
	temp[3]=r[i][3];
	count=0;
	counter+=r[i+1][2];
	i++;
	while(i<=N){
		if((counter-count) == temp[1]){
			counter+=r[i+1][2];
			std::cout<<temp[0]<<"\t"<<temp[1]<<"\n";
			count+=temp[1];
			if (mpq.empty())
			{
				for (int j = 0; j < 4; ++j)
				{
					temp[j]=r[i][j];
				}
				i++;
				continue;

			}
			else{
				//take below this in temp
				t= mpq.extract_min();
				for (int j = 0; j < 4; ++j)
				{
					temp[j] = t[j];
				}
				if(temp[3]<r[i][3]){
					mpq.insert(r[i][3],r[i][0],r[i][1],r[i][2]);
					//mpq.insert_2d(r[i][0],r[i][1],r[i][2]);
					i++;
					continue;
				}
				else{
					mpq.insert(temp[3],temp[0],temp[1],temp[2]);
//					mpq.insert_2d(temp[0],temp[1],temp[2]);
					for (int j = 0; j < 4; ++j)
					{
						temp[j]=r[i][j];
					}
					i++;
					continue;
				}

			}
}
		else if ((counter-count) > temp[1])
		{
			std::cout<<temp[0]<<"\t"<<temp[1]<<"\n";
			count+=temp[1];
			if (mpq.empty())
			{

				std::cout<<"CPU\t"<<counter-count<<"\n";
				count+=(counter-count);
				for (int j = 0; j < 4; ++j)
				{
					temp[j]=r[i][j];
				}
				counter+=r[i+1][2];
				i++;
				continue;
			}
			else{
				//take below this in temp
				t= mpq.extract_min();
				for (int j = 0; j < 4; ++j)
				{
					temp[j] = t[j];
				}
				continue;
			}
		}
		else if ((counter-count) < temp[1]){
			std::cout<<temp[0]<<"\t"<<(counter-count)<<"\n";
			temp[1]=temp[1] - (counter-count);
			count+=(counter-count);
			//i++;
			counter+=r[i+1][2];
			if (r[i][3] < temp[3])	//priority value of incoming instruction is high
			{
				mpq.insert(temp[3],temp[0],temp[1],temp[2]);
//				mpq.insert_2d(temp[0],temp[1],temp[2]);
				for (int j = 0; j < 4; ++j)
				{
					temp[j]=r[i][j];
				}
				i++;
				continue;

			}
			else{
				//load r[i+1] in heap
				mpq.insert(r[i][3],r[i][0],r[i][1],r[i][2]);
				//mpq.insert_2d(r[i][0],r[i][1],r[i][2]);
				i++;
				continue;
			}
		}
	}
	return 0;
}

/*4
10
25
0
4
12
10
15
2
6
35
20
6
10
30
50
4
*/
