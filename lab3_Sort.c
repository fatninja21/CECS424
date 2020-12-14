/*
Wilfredo Mendivil
CECS 424 Assignment 3- lab3.c
Due date : 4 / 7 / 2020
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struct person
struct Person
{
	char* name; //char pointer to name of person
	int age; //integer value holding the age of person
};

//compares two values type void*
int compare_float(void* a, void* b)
{
	return ((*(float*)a) - (*(float*)b));
}

//compare name of person
int comp_person_name(const void* a, const void* b)
{
	struct Person* temp_a = (struct Person*)a; //temp value holding Person a
	struct Person* temp_b = (struct Person*)b;//temp value holding Person b

	// Sort by name first then age
	if (strcmp(temp_a->name, temp_b->name) == 0) //compares two strings pointed to
		return (temp_a->age - temp_b->age); //if name is equal compare age

	return strcmp(temp_a->name, temp_b->name);//otherwise compare name
}
//compare age of person
int comp_person_age(const void* a, const void* b)
{
	struct Person* temp_a = (struct Person*)a;//temp value holding Person a
	struct Person* temp_b = (struct Person*)b;//temp value holding Person b

	// Sort by age first then name
	if ((temp_b->age - temp_a->age) == 0) //check if age is equal
		return (strcmp(temp_a->name, temp_b->name)); // compare by name if age is equal
	return (temp_b->age - temp_a->age);//otherwise compare by age
}
//print float array
void print_float_array(float* arr, int size)
{
	for (int i = 0; i < size; i++) {//itterate through aray
		printf("%.2f, ", arr[i]);//print formatted
	}
	printf("\n");//print empty line after loop ends
}
//print person array
void print_person_array(struct Person* arr, int size)
{
	for (int i = 0; i < size; i++) {//itterate through person array
		printf("%s, %d\n", arr[i].name, arr[i].age);//print formated person
	}
	printf("\n");//print empty line after loop ends
}

int main()
{
	// Sorting array of integers
	float numbers[] = { 645.32,37.40,76.30,5.40,-34.23,1.11,-34.04,23.37,635.46,-876.22,467.73,62.26 };
	int numbers_size = sizeof(numbers) / sizeof(numbers[0]);//size of numbers array by retrieving the byte size of numbers and dividing by a value inside
	qsort(numbers, numbers_size, sizeof(int), compare_float);//call quicksort with specific generic compare function
	printf("sorted float array is:\n");//print statement
	print_float_array(numbers, numbers_size);//print float array 
	printf("\n");//print empty line

	// Sorting array of structures
	struct Person people[] = {
		[0] .name = "Hal",[0].age = 20,
		[1].name = "Susann",[1].age = 31,
		[2].name = "Dwight",[2].age = 19,
		[3].name = "Kassandra",[3].age = 21,
		[4].name = "Lawrence",[4].age = 25,
		[5].name = "Cindy",[5].age = 22,
		[6].name = "Cory",[6].age = 27,
		[7].name = "Mac",[7].age = 19,
		[8].name = "Romana",[8].age = 27,
		[9].name = "Doretha",[9].age = 32,
		[10].name = "Danna",[10].age = 20,
		[11].name = "Zara",[11].age = 23,
		[12].name = "Rosalyn",[12].age = 26,
		[13].name = "Risa",[13].age = 24,
		[14].name = "Benny",[14].age = 28,
		[15].name = "Juan",[15].age = 33,
		[16].name = "Natalie",[16].age = 25
	};

	int person_size = sizeof(people) / sizeof(people[0]);//retrieve length of person array by getting the byte size of the array and dividing by the byte size of 1 value in the array
	qsort(people, person_size, sizeof(struct Person), comp_person_name);//call quick sort with specific compare person name
	printf("Sorted People by Name:\n");//print statement
	print_person_array(people, person_size);//calls method to print people arraylist

	qsort(people, person_size, sizeof(struct Person), comp_person_age);// call quick sort with specific compare person age
	printf("Sorted People by Age:\n");//print statement
	print_person_array(people, person_size);//calls method to print people arraylist

}