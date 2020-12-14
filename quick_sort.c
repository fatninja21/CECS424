/*Wilfredo Mendivil
CECS424 Assignment1 quick_sort.c
due date: 02/11/2020 9:30 AM
*/


/*method to swap values in an array*/
void Swap(int arr[], int a, int b) {
	int temp = arr[a];//hold the value from the first input into temp
	arr[a] = arr[b];//replace the first imput location in the array with second
	arr[b] = temp;//replace second input location value with temp
}
/*calulcates pivot by finding the median of three for best run time*/
/*returns the pivot index*/
int calculatePivot(int arr[], int left, int right)
{
	int middle = (right + left) / 2;//set middle value
	int pivot = 0;//initialize pivot
    /*checks condition to see if pivot is left*/
	if ((arr[left] > arr[middle]) && (arr[left] < arr[right]) || ((arr[left] < arr[middle]) && (arr[left] > arr[right]))) 
	{
		pivot = left;//set pivot to left value
	}
	/*checks condition to see if pivot is right*/
	else if ((arr[right] > arr[middle]) && (arr[right] < arr[left]) || ((arr[right] < arr[middle]) && (arr[right] > arr[left]))) 
	{
		pivot = right;//set pivot to right
	}
	/*checks condition to see if pivot is middle*/
	else if ((arr[middle] > arr[left]) && (arr[middle] < arr[right]) || ((arr[middle] > arr[right]) && (arr[middle] < arr[left])))
	{
		pivot = middle;//set pivot to middle
	}
	else if ((arr[middle] > arr[right]) && (arr[middle] < arr[left])) 
	{
		pivot = middle;
	}
	/*this portion swaps the index of pivot w/ the last value of the array*/
	if (pivot == left) 
	{
		Swap(arr, right, left);//swap left and right value
		pivot = right;//set pivot to right now that right holds the median value
	}
	else if (pivot == middle)
	{
		Swap(arr, middle, right);//swap middle and right value
		pivot = right;//set pivot to right now that right holds the median value
	}
	else {
		pivot = right;//median is right
	}

	return pivot;//return the pivot index
}
/*calls calculatePivot in order to compare left and right-1 value against it 
in order to sort the array*/
int Partition(int a[], int left, int right) 
{
	int pivotIndex = calculatePivot(a, left, right);//calculate median of 3 as pivot
	int pivot = a[pivotIndex];//set pivot to the value of median in the array
	int leftPointer = left;//set left pointer to left value of  array
	int rightPointer = right - 1;//set right pointer to right -1 since pivot is right most value
	int temp = 0;//holds temp value
	
	/*loops until a break statement happens swapping values to sort the array
	breaks when leftpointer and right pointer cross*/
	while (1) 
	{
		/*checks to see that leftpointer value is less than pivot and left pointer does not cross right pointer*/
		while (a[leftPointer] <= pivot && leftPointer < rightPointer)
		{
			leftPointer++;// increment because a[leftPointer]> pivot
		}
		/*checks to see that rightPointer value is greater than 0
		and right pointer is greater than pivot*/
		while (rightPointer > 0 && a[rightPointer] >= pivot)
		{
			rightPointer--;// decrement because a[rightPointer]> pivot
		}
		/*condition to break from the while loop*/
		if (leftPointer > rightPointer) 
		{
			break;// gets out of while loop when the if statement condition is met
		}
		/*if the value held in left pointer and right pointer are the same
		increcrement leftPointer and decrement rightpointer*/
		else if (a[leftPointer] == a[rightPointer])
		{
			leftPointer++;//increment left pointer
			rightPointer--;//decrement right pointer
		}
		//if above conditions arent met
		else
		{
			temp = a[leftPointer];//temp value holds value at left pointetr
			a[leftPointer] = a[rightPointer];//value at left pointer swaped with right pointer value
			a[rightPointer] = temp;//value at right pointer swaped with temp value
		}
	} // end while true
	/*after while loop is broken swap left pointer value with the right value(
	(previous pivot)*/
	temp = a[leftPointer];//temp value holds value of left pointer
	a[leftPointer] = a[right];//left pointer swaped with value of right(current pivot)
	a[right] = temp;//right value is now temp value

	return leftPointer;// this value is the new pivot

}// end partition function

/*recursively runs through quick_sort in order to sort the array*/
void quick_sort(int *a, int left, int right)
{
	/*if right=left>1 recursively call quickSort on left and right side of pivot*/
	if (right - left > 1) 
	{
		int pIndex = Partition(a, left, right);//caluclate pivot index by calling parition function
		quick_sort(a, left, (pIndex - 1));//quick_sort with left value and current pivot index -1
		quick_sort(a, (pIndex + 1), right);//quick_sort with pivot value+1 to the very right
	}
	/*array size of current iteration is 2*/
	else if (right - left == 1) 
	{ 
		if (a[left] > a[right])//swap if out of order
		{ 
			Swap(a, left, right);//swap last 2 values to finish the sort
		}
	}

}
/*method calls premade method in order to sort an array*/
void quick2(int *a, int  n)
{
	int left = 0;//initialize left value
	int right = n;//initialize right value
	quick_sort(a, left, right);//calls premade method for quick_sort
}

