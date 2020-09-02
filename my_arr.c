#include <stdio.h>
#include <stdlib.h>

const int MAX = 1000;

void* zeros(int, int*);

/*
 * Inside of main there are three demonstrations for array declairation.
 * the first is using pointer arithmetic to define the first and last 
 * locations, in memory, of the array. The second is the standard way.
 * The third is heap allocation. All three result in similar out comes
 * when applying the zeros function to them.
 */

int main(void)
{
	int *x,*p; //Allocating the beginning location in memory
	p = x;     // p acts as the storage of the start location (x[0])
	x = p + (sizeof *x)*10; // Improperly sized array. To demo undefined behavior.
	//int x[MAX];  // Standard array assignment
	//int *x = malloc(sizeof(int)*MAX);  // Heap array assignment
	zeros(MAX, x); //Filling the array with 0's
	//int i;
	//for(i = 0; i < MAX; ++i)
	printf("%d %p %d\n", MAX-1, &x[MAX-1], x[MAX-1]);
}

/*
 * The following function can result in undefined behavior if it is not
 * implemented properly. It will assign values outside of array if the 
 * array is not properly sized or declaired.
 *
 * The undefined behavior is either random value assignments, or over
 * writing memory.
 */

void* zeros(int n, int *x)
{
	void *end = &x[n];     // Defining the "NULL" location of the array
	for(x; x != end; x++){ // Traversing the array using pointer arithmetic
		*x = 0;            // Assigning the value of 0 to each array location
	}
}
