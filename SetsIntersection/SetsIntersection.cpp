// Sets Intersection: Let A and B be the sets of size n with elements in {0,1,2,3,4,5,6,7,8,9}. Find elements that belong to both sets A and B.
// Goal: Minimize the number of comparisons.

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL)); 
	int size = 15; 
	int comparisonCounter = 0;
	int primes[10] = {2,3,5,7,11,13,17,19,23,29}; //Array of first 10 primes

	cout<<"The size of sets A and B is "<<size<<endl;
	int* setA = new int[size];
	int* setB = new int[size];

	cout<<"Set A\tSet B"<<endl;
	for (int i = 0; i < size; i++)
	{
		setA[i] = i % 10;
		setB[i] = rand() % 10;
		cout<<setA[i]<<"\t"<<setB[i]<<endl;
	}
	cout<<endl;

	int* primesSetA = new int[size];
	int* primesSetB = new int[size];
	cout<<"Primes product algorithm (n comparisons):"<<endl;
	cout<<"Replace elements of sets A and B with corresponding primes:"<<endl; //We substitute n with n-th prime (2 is the 1st prime, 3 is 2nd, 5 is 3rd, ...)
	cout<<"Set A\tSet B"<<endl;
	for (int i = 0; i < size; i++)
	{
		primesSetA[i] = primes[setA[i]];
		primesSetB[i] = primes[setB[i]];
		cout<<primesSetA[i]<<"\t"<<primesSetB[i]<<endl;
	}
	cout<<endl;

	long long product = 1;
	cout<<"Multiply all elements in set A:"<<endl;
	for (int i = 0; i < size;i++)
	{
		product *= primesSetA[i];
	}
	cout<<"Product = "<<product<<endl<<endl;

	cout<<"Try to divide Product by each element of set B:"<<endl;
	for (int i = 0; i < size; i++)
	{
		comparisonCounter++;
		if(product % primesSetB[i] == 0) //Comparison that we count
		{
			cout<<primesSetB[i]<<" divides "<<product<<" with no remainder.\t"<<setB[i]<<" belongs to both sets A and B."<<endl;
			product /= primesSetB[i];		
		}
	}

	cout<<endl;
	cout<<"Number of comparisons: "<<comparisonCounter<<endl<<endl<<endl;

	comparisonCounter = 0;
	cout<<"Trivial algorithm (O(n^2) comparisons):"<<endl;
	cout<<"Common elements are:";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			comparisonCounter++; 
			if(setA[i] == setB[j]) //Comparison that we count
			{
				cout<<" "<<setA[i];
				setB[j] = -1;
				break;
			}
		}
	}
	cout<<endl<<endl;
	cout<<"Number of comparisons: "<<comparisonCounter<<endl<<endl;
	return 0;
}

