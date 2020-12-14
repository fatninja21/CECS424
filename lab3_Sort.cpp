/*
Wilfredo Mendivil
CECS 424 Assignment 3 - Lab3.cpp
Due date : 4 / 7 / 2020
*/

#include <iostream>
#include <string.h>
#include <algorithm> //used for sort

using namespace std;
//struct of type person
struct Person 
{	//parameters of person
	string name; //name of person
	int age;//age of person
};

//overload operator ==
bool operator==(const Person& p1, const Person& p2)
{
	return (p1.name == p2.name && p1.age == p2.age); 
}
//overload operator !
bool operator!=(const Person& p1, const Person& p2)
{
	return !(p1 == p2); 
}
//overload operator <
// used to compare by name and if names are the same by age
bool operator<(const Person& p1, const Person& p2)
{
	if (p1.name == p2.name) // If the person has the same name
		return p1.age < p2.age; // then compare the age
	return p1.name < p2.name; // otherwise compare the name
}
//overload output operator
//format the output of the Person in the array
ostream& operator<<(ostream& out, const Person& p)
{
	out << "\n" << p.name << ":   " << p.age; // prints to screen person followed by name
	return out; // return output statement
}


// Print elements in an array (int, float, char, string)
template<class T>
void print_array(T arr[], int size) // takes in an array of any type, and a size of the array
{
	for (int i = 0; i < size; i++) //loops through
		cout << arr[i] << " ";//prints value in position i
	cout << "\n";//at the end of the loop print an empty line
}


// Compare function for sorting array of structures
int cmp_person_age(Person a, Person b)
{
	// Sort by age first then name
	if (a.age== b.age) //checks to see if age is equal
		return a.name < b.name; //if equal compare name
	return b.age < a.age; // otherwise compare age
}

int main()
{
	// Sorting array of integers
	float numbers[12] = { 645.32,37.40,76.30,5.40,-34.23,1.11,-34.04,23.37,635.46,-876.22,467.73,62.26 }; //list of float values
	int num_arr_size = sizeof(numbers) / sizeof(numbers[0]); //size of the array is retrieved by getting the number of bytes and dividing it by the size of a single value

	sort(numbers, numbers + num_arr_size); //takes in the begining value and ending value of the array as a parameter
	printf("Sorted Numbers:\n"); //print statement
	print_array(numbers, num_arr_size); //prints the array of numbers to the screen
	printf("\n"); //prints empty line to the screen

	// Sorting array of structures
	Person people[] = //initialize people array of type Person
	{
		{"Hal", 20},
		{"Susann",31},
		{"Dwight", 19},
		{"Kassandra", 21},
		{"Lawrence", 25},
		{"Cindy", 22},
		{"Cory", 27},
		{"Mac", 19},
		{"Romana", 27},
		{"Doretha", 32},
		{"Danna", 20},
		{"Zara", 23},
		{"Rosalyn", 26},
		{"Risa", 24},
		{"Benny", 28},
		{"Juan", 33},
		{"Natalie", 25}
	};
	int person_size = sizeof(people) / sizeof(people[0]); //size of people array

	sort(people, people + person_size); //sort takes in initial value of array and last value
	printf("Sorted People by Name:"); //print statement
	print_array(people, person_size);//print the array of people
	printf("\n"); //print empty line

	sort(people, people + person_size, cmp_person_age); //sort takes in initial value of array and last value and parameter wanting to sort
	printf("Sorted People by Age:"); //print statement
	print_array(people, person_size); //print the array of people
	printf("\n");//print empty line
}