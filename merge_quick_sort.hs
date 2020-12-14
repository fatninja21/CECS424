merge :: Ord a => [a] -> [a] -> [a] -- merge two sorted lists to a sorted list of type a 
merge [] ys = ys                    -- if one value in list
merge xs [] = xs                    --   or the other list is empty merging is trivial
merge (x:xs) (y:ys)                 -- merge two non-empty lists
  | x <= y    = x : merge xs (y:ys)     -- if the left element is smaller then output it first
  | otherwise = y : merge (x:xs) ys     --   otherwise output the right element first

divide :: [a] -> ([a],[a]) -- divide a list into a set of two lists
divide [] = ([],[])        -- first condition if list is empty then the result is two empty lists
divide [x] = ([x],[])      -- if list has only one item then one of the two resulting lists will be an empty list
divide xs = (take divx xs, drop divx xs) -- divide a non-empty list into left and right halves
             where divx = length xs `div` 2 -- divide length of x by 2

msort :: Ord a => [a] -> [a] --take in list a sort it with mergesort and retun the list a
msort []  = [] -- condition if list is empty
msort [x] = [x] --if list is sorted then return list 
msort xs  = merge (msort left) (msort right)-- merge t2 lists
   where (left, right) = divide xs  --divide by input list






--module to be called in order to sort an array by quick_Sort
--ord allows values of type a to be compared against one another
qsort :: Ord a => [a] -> [a]-- takes any function of type a and yields a function that takes a list of a's and produces a list of a's
qsort [] = [] -- first condition of an empty array if list is empty return an empty list
qsort (x:xs) = (qsort lesser) ++ [x] ++ (qsort greater)--if list is not empty take first value & append with taking qsort lesser and qsort greater
    where
      lesser = filter (< x) xs--get xs values as they are less than x (sorts the actual values less than to be appended)
      greater = filter (>= x) xs--get elements of xs as they are greater than or equal to x(sorts the actual values greater than to be appended)
 --module to be called for quicksort merges lists
 
 
main = do --used to call main
    putStrLn "array before sort is :[4,65,2,-31,0,99,2,83,782,1]"--prints non sorted array
    putStrLn "array quicksorted is:" --prints string to screen   
    print(qsort [4,65,2,-31,0,99,2,83,782,1])--will call quicksort 
    putStrLn " array before sort is :[4,65,2,-31,0,99,2,83,782,1]"--prints non sorted array
    putStrLn "array after mergesort is:"--prints string to screen
    print(msort [4,65,2,-31,0,99,2,83,782,1])--calls mergeSort

