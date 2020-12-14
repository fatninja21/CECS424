'''
Wilfredo Mendivil
CECS 424 Assignment 3
Due date: 4/7/2020
'''


#List of float Numbers
numbers = [645.32, 37.40, 76.30,  
           5.40, -34.23, 1.11,
           -34.94, 23.37, 635.46,
           -876.22, 467.73, 62.26]
numbers.sort() #sort the numbers list consisting of float numbers
print("Sorted FLoat numbers:\n " ,*numbers,"\n") # print the numbers list after it is sorted

#person object
class Person:
    def __init__ (self, name, age): #parameters of person is name, age
        self.name = name   #define name         
        self.age = age     #define age
    def __str__(self):#make person age and name into string
        return str(self.name) + "-" + str(self.age) + "\n"  #return format of how perosn will be printed

#list of people
people = [Person("Hal", 20), 
          Person("Susann", 31),
          Person("Dwight", 19),
          Person("Kassandra", 21), 
	      Person("Lawrence", 25),
          Person("Cindy", 22),
          Person("Cory", 27), 
          Person("Mac", 19),
          Person("Romana", 27), 
          Person("Doretha", 32),
          Person("Danna", 20), 
          Person("Zara", 23), 
          Person("Rosalyn", 26), 
          Person("Risa", 24), 
          Person("Benny", 28),
          Person("Juan", 33), 
          Person ("Natalie", 25)]

#sort people list by name
people.sort(key = lambda Person: Person.name) # uses lambda to specify the list will be sorted by person's name
print("People sorted by Name:")
print(*people) #prints people in incrementing order by First letter

#sort People list by name. Reverses the order to print in decrementing order
people.sort(key = lambda Person: Person.age, reverse= True)# uses lambda to specify the list will be sorted by person's name. 
print("People sorted by Age:") #print statement
print(*people) #print the list in decrementing order
