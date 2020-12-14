/*
Wilfredo Mendivil
CECS 424 Assignment 3 - Lab3.cs
Due date : 4 / 7 / 2020
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
	class GenericSort
	{

		//struct of type person
		struct Person
		{   //parameters of person
			public string name; //name of person
			public int age;//age of person
		}

		//method to print any generic value from an array
		public static void printNumber<T>(T[] array)
		{
			for (int i = 0; i < array.Length; i++)//itterate through array
			{
				Console.WriteLine(array[i].ToString(), " "); //print a statement with the value converterd to string
			}
			Console.WriteLine("");//print empty line at the end
		}

		// Print elements in array (struct) 
		static void printPerson(Person[] array) 
		{
			for (int i = 0; i < array.Length; i++) //itterate through array
			{
				Console.WriteLine(array[i].name + ":  " + array[i].age + " "); //print formatted name and age for every person in array
			}
			Console.WriteLine(""); //print empty line after for loop has finished
		}

		// Compare function for sorting array of structures
		static int compare_person_name(Person a, Person b)
		{
			// Sort by age first then name
			if (b.name.CompareTo(a.name)== 0) //checks to see if name is equal
				return b.age.CompareTo(a.age); //if equal compare age
			return a.name.CompareTo(b.name); // otherwise compare name
		}

		// Compare function for sorting array of structures
		static int compare_person_age(Person a, Person b)
		{
			// Sort by age first then name
			if (a.age.CompareTo(b.age)==0) //checks to see if name is equal
				return  a.name.CompareTo(b.name); //if equal compare age
			return b.age.CompareTo(a.age); // otherwise compare name
		}
		// Testing below
		static void Main()
		{
			// Sorting array of integers
			float[] numbers = { 645.32f, 37.40f, 76.30f, 5.40f, -34.23f, 1.11f, -34.04f, 23.37f, 635.46f, -876.22f, 467.73f, 62.26f }; //list of float values
			Array.Sort(numbers); //sort numbers array by integrated method
			Console.WriteLine("Sorted Float Values ");// write to screen
			Console.WriteLine("");//print empty line
			printNumber(numbers);//call printNumber function to print number array sorted

			//add values to people array
			Person[] people = { new Person() { name = "Hal", age = 20 }, 
				     new Person() { name = "Susann", age = 31},
					 new Person() { name = "Dwight", age = 19},
					 new Person() { name = "Kassandra",age = 21},
					 new Person() { name = "Lawrence", age = 25},
					 new Person() { name = "Cindy", age = 22},
					 new Person() { name = "Cory", age = 27},
					 new Person() { name = "Mac", age = 19},
					 new Person() { name = "Romana", age = 27},
					 new Person() { name = "Doretha", age = 32},
					 new Person() { name = "Danna", age = 20},
					 new Person() { name = "Zara", age = 23},
					 new Person() { name = "Rosalyn", age = 26},
					 new Person() { name = "Risa", age = 24},
					 new Person() { name = "Benny", age = 28},
					 new Person() { name = "Juan", age = 33},
					 new Person() { name = "Natalie", age = 25} };
			Array.Sort<Person>(people, compare_person_name); // sort people array by name
			Console.WriteLine("Sorted by Name ");//print message to screen
			printPerson(people); //print array to screen
			Console.WriteLine(""); //print line
			Array.Sort<Person>(people, compare_person_age); //sort people array by age
			Console.WriteLine("Sorted by age "); //print message to screen
			printPerson(people);//print people array sorted by age

		}

	}

}