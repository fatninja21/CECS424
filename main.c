/*Wilfredo Mendivil
CECS424 Assignment 1 main.c
DUE DATE: 02/11/2020 9:30AM
*/


#include <stdio.h>
#include <stdlib.h>

/*itterate through array given size and array and print to screen*/
void printArray(int a[], int size)
{
	/*loop through array until reaches end*/
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);//print value to screen
		printf("\n");//print empty line
}
/*test conditions*/
int main()
{
	int array[10] = { 4,65,2,-31,0,99,2,83,782,1 };//initialize array with given values
	int array2[10] = { 4,65,2,-31,0,99,2,83,782,1 };//initialize array with given values
	int length = sizeof(array) / sizeof(array[0]);//sets length of array1
	int length2 = sizeof(array2) / sizeof(array2[0]);//sets length of array2
	printf("Non sorted array is\n");//print statement to display
	printArray(array, length);//call printArray to print non sorted array1
	msort(array,length-1);//call mergesort function
	printf("Array sorted after calling Merge sort\n");
	printArray(array, length);//call printArray to print sorted array1
	printf("Non Sorted array\n");//print statement to screen
	printArray(array2, length2);//call printArray to print non sorted array2
	quick2(array2, length2 - 1);//call quicksortfunction
	printf("Array Sorted after calling quick_sort\n");//print statement to screen
	printArray(array2, length2);//call printArray to print sorted array2

	return 0;
}