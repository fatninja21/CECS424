--Assignment 3- lab3.hs
--Wilfredo Mendivil
--017471907
--Due Date: 4/7/2020 at 9:30 

--Quicksort function. 
quickSort :: Ord a => [a] -> [a]  --use Ord to compare something type a. use a list to compare and return a list
quickSort [] = [] --initial parameter
quickSort (x:xs) = quickSort [y | y <- xs, y <= x] ++ [x] ++ quickSort [y | y <- xs, y > x] --quick sort both sides. if y is les than or equal to x it will be add x to the end and followed by the restof the list


data  Person = Person String Int deriving (Show,Eq) --person class holds a string and an int
name :: Person -> String --name is the string
name    (Person n a) = n --name is the first parameter

age :: Person ->Int --age is the int
age     (Person n a) = a --age is the second parameter

instance Ord Person where --goes through instances of person to be used in quick
    compare x y =  --compares 2 values
        let 
            i = compare (name x) (name y) --compare the name of two objects 
        in      
            if i == EQ then compare (age x) (age y) --if name is equal compare age
            else i  --otherwise compare name

data Person2 = Person2 String Int deriving (Show, Eq) --second person class
name2 :: Person2 -> String--name is the string
name2     (Person2 n a) = n--name is the first parameter

age2  :: Person2 ->Int --age is the int
age2     (Person2 n a) = a --age is the second parameter

instance Ord Person2 where --looks through instances where person2 is being compared
    compare x y = --compare 2 types
        let
		    i = flip compare (age2 x) (age2 y) --compare the age of two objects 
		in
		    if i == EQ then compare (name2 x) (name2 y)--if age is equal compare name
			else i   --otherwise compare age

          
            

main = do 
    putStrLn " list number after quickSort : " --print 
    print (quickSort [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]) --print quicksorted values of floats in list
  
    putStrLn " Person sorted by Name" -- print message to screen
    print(quickSort[ Person "Hal" 20, --quicksort and print person list to screen sorted alphabetically
                              Person "Susann"31, 
                              Person "Dwight"19,
                              Person "Kassandra" 21,
                              Person "Lawrence" 25, 
                              Person "Cindy" 22,
                              Person "Cory" 27,
                              Person "Mac" 19,
                              Person "Romana" 27,
                              Person "Doretha" 32,
                              Person "Danna" 20,
                              Person "Zara" 23,
                              Person "Rosalyn" 26,
                              Person "Risa" 24,
                              Person "Benny" 28,
                              Person "Juan" 33,
                              Person "Natalie" 25])
							  
    putStrLn " Person sorted by Age"--print message to screen
    print(quickSort[ Person2 "Hal" 20,--quicksort and print person2 list to screen sorted numerically decending
                              Person2 "Susann"31,
                              Person2 "Dwight"19,
                              Person2 "Kassandra" 21,
                              Person2 "Lawrence" 25,
                              Person2 "Cindy" 22,
                              Person2 "Cory" 27,
                              Person2 "Mac" 19,
                              Person2 "Romana" 27,
                              Person2 "Doretha" 32,
                              Person2 "Danna" 20,
                              Person2 "Zara" 23,
                              Person2 "Rosalyn" 26,
                              Person2 "Risa" 24,
                              Person2 "Benny" 28,
                              Person2 "Juan" 33,
                              Person2 "Natalie" 25])