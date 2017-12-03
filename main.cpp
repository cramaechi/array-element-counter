//A progam that reads in an array and prints out, in a two column format,
//the distinct elements of the array in one column, and the number of its occurences
//on the second column. 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

void input(int a[], int arraySize, int& numberUsed);
//Precondition: arraySize > 0 && < 50. numberUsed > 0 && <= arraySize.
//Postcondition: array a has been filled.

void trackElementOccurence(const int a[], int numberUsed, int e[]);
//Precondition: array a has been filled. numberUsed >= 1. Array a cannot be changed.
//Postcondition: array e has been filled.

int keepCount(const int a[], int numberUsed, int targetIndex);
//Precondition: array a has been filled. numberUsed and targetIndex >= 1.
//Postcondition: Returns the number of occurences for each element of 
//array a.

void sort (int a[], int numberUsed);
//Precondition: array a has been filled. numberUsed >= 1.
//Postcondition: Sorts the elements of array a from largest 
//to smallest.

int indexOfLargest(const int a[], int size, int startIndex);
//Precondition: array a is filled and cannot be changed. size is
//the declared size of array a. startIndex >= 0.
//Postcondition: Returns an index with the next largest element.

void swap(int& n1, int& n2);
//Precondition: n1 and n2 >= 1.
//Postcondition: Interchanges the values of n1 and n2.

void deleteRepeats(int a[], int e[], int& numberUsed);
//Precondition: array a and e have been filled. numberUsed
//>= 1.
//Postcondition: Deletes all repeats of each distinct element in 
//array e and a.

void pushElementForward(int a[], int e[], int& numberUsed, int refillIndex);
//Precondition: array a and e have been filled. numberused is >= 1.
//refillIndex >= 0.
//Postcondition: Reassigns the values of each element in array e and a
//to the succeeding adjacent element.

void searchReplica(int a[], int e[], int& numberUsed, int targetIndex);
//Precondition: array a and e have been filled. numberUsed >= 1.
//targetIndex >= 0.
//Postcondition: Searches array a for duplicates values of its elements.

void output(int a[], int numberUsed, const int e[]);
//Precondition: Array a has been filled. numberUsed > 0 && <= arraySize.
//Postcondition: outputs two columns in which one column indicates
//the each distinct element of array a and the other indicates the 
//number of occurences.

const int ARRAY_SIZE = 50;

int main()
{
	int a[ARRAY_SIZE], e[ARRAY_SIZE], numberUsed;

	input(a, ARRAY_SIZE, numberUsed);
	sort(a, numberUsed);
	trackElementOccurence(a, numberUsed, e);
	deleteRepeats(a, e, numberUsed);
	output(a, numberUsed, e);

	return 0;
}

void input(int a[], int arraySize, int& numberUsed)
{
	int index = 0;

	cout<<"Enter up to "<<arraySize<<" numbers: ";
	
    do
	{
		cin>>a[index++];
	}while(cin.peek() != '\n' && index < arraySize);
    cout<<endl;

	numberUsed = index;
}

void trackElementOccurence(const int a[], int numberUsed, int e[])
{
	for (int i = 0; i < numberUsed; i++)
		e[i] = keepCount(a, numberUsed, i);
}

int keepCount(const int a[], int numberUsed, int targetIndex)
{
	int count = 1;

	for (int j = numberUsed - 1; j > targetIndex; j--)
	{
		if (a[j] == a[targetIndex])
			++count;
	}

	return count;
}

void sort(int a[], int numberUsed)
{
	int indexOfNextLargest;

	for (int i = 0; i < numberUsed - 1; i++)
	{
		indexOfNextLargest = indexOfLargest(a, numberUsed, i);
		swap(a[i], a[indexOfNextLargest]);
	}
}

int indexOfLargest(const int a[], int size, int startIndex)
{
	int max = a[startIndex], indexOfMax = startIndex;

	for (int index = startIndex + 1; index < size; index++)
	{
		if (a[index] > max)
		{
			max = a[index];
			indexOfMax = index;
		}
	}

	return indexOfMax;
}

void swap(int& n1, int& n2)
{
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}

void deleteRepeats(int a[], int e[], int& numberUsed)
{
	for (int i = 0; i < numberUsed - 1; i++)
		searchReplica(a, e, numberUsed, i);
}

void searchReplica(int a[], int e[], int& numberUsed, int targetIndex)
{
	for (int index = numberUsed - 1; index > targetIndex; index--)
	{
		if (a[index] == a[targetIndex])
			pushElementForward(a, e, numberUsed, index);
	}
}

void pushElementForward(int a[], int e[], int& numberUsed, int refillIndex)
{
	for (int startIndex = refillIndex; startIndex < numberUsed; startIndex++)
	{
		e[startIndex] = e[startIndex + 1];
		a[startIndex] = a[startIndex + 1];
	}

	numberUsed--;
}

void output(int a[], int numberUsed, const int e[])
{
	cout<<setw(8)<<"Integer"<<setw(9)<<"Count\n";
	
	for(int i = 0; i < numberUsed; i++)
		cout<<setw(2)<<a[i]<<setw(10)<<e[i]<<endl;
}
