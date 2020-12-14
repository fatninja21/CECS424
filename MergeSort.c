/*Wilfredo Mendivi
CECS424 Assignment1 MergeSort.c
Due Date:02/11/2020 9:30AM
*/

/*takes in an array,and locations in order to 
create a temporary array itterate and add values as it sorts
once sorted it adds them back to the original array in sorted order*/
void merge(int a[], int left, int middle, int right)
{
	int* ordered_array = (int*)malloc(sizeof(int) * (right - left + 1));//allocate memory to be used 
	int iFirst = left; // index to iterate through the first half
	int iSecond = middle + 1; // index to iterate through the second half
	int i = 0; // index of current location in array a
	/*checks to make sure left and right pointer dont go out of bounds*/
	while (iFirst <= middle && iSecond <= right)
	{
		/*checks value of left pointer location against right pointer*/
		if (a[iFirst] < a[iSecond])
		{
			ordered_array[i] = a[iFirst];//add value to temp array
			iFirst++;//increment left side pointer
		}
		/*if value held in second is smaller than first*/
		else {
			ordered_array[i] = a[iSecond]; // element in the second half is smaller
			iSecond++;//increment right side pointer
		}
		i++; // increment the current position of a
	}

	/*accounting for leftover elements of left half*/
	while (iFirst <= middle) 
	{
		ordered_array[i] = a[iFirst];//add value from left pointer to temp array
		iFirst++;//increment left pointer counter
		i++;//increment current index of array
	}//end while (isecond< firstHalf.length)

	/*accounting for leftover elements of right half*/
	while (iSecond <= right) 
	{
		ordered_array[i] = a[iSecond];//add right side pointer values to temp array
		iSecond++;//increment right side pointer
		i++;//increment current position of array
	}//end while (isecond< secondHalf.length)
	/*loops to add values back into initial array in sorted order*/
	for (int y = 0; y < i; y++) {//loop to add values from temp array to a
		a[left+y] = ordered_array[y];//itterate until values are added to original array sorted
	}
	free(ordered_array);//free up space allocated for temp array
}//end merge

/*recursively sorts by calling quick sort in two halves*/
void merge_sort(int *a, int left, int right)
{
	/*makes sure array length is greater than 1*/
	if (right > left)
	{
		int middle = (left + right) / 2;//set middle value
		merge_sort(a, left, middle);//recursive call left to mid of array
		merge_sort(a, middle + 1, right);//recursive call mid+1 to right most value of array
		merge(a, left, middle, right);//combine values
	}
}//end sort

/*calls premade function of mergesort*/
void msort(int* a, int n)
{
	int left = 0;//set value for left most value of array
	int right = n;//set value for right most value of array
	merge_sort(a, left, right);//call my own merge sort function
}

