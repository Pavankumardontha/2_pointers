# Problems
1) Count pairs with given sum (gfg not exactly 2 pointers)
2) Minimum window substring (leetcode)

# purely 2 pointer problem and quite obvious
1) 2 sum - 1
2) 2 sum - 2
3) 3 sum  -> Run outerloop for 1st element and search the other 2 elements using 2 pointers method. We need to eliminate duplicates at the outer loop and also inside the 2 pointer method.
4) 4 sum -> Run outerloops for 1st and 2nd elements. Find 3rd and 4th using 2 pointers method. Handle the duplicate condition at the ith loop , jth loop and also inside the 2 pointers method.
5) 3 sum closest -> same like 3 sum . Calculate the sum and if sum<target -> start++ or end--. Always store the closest sum to the given target in some variable and compare for each case.
6) Merge Two 2D Arrays by Summing Values 
7) Sort Array By Parity
8) Sort array by parity - 2 - Here take 2 pointers starting with an even and odd index and increment them by 2 till the condition is met. Swap the elements at the
   point of condition failure.
9) Rearrange Array Elements by Sign  - CANNOT BE SOLVED IN-PLACE. Should use extra space and its easy to solve.
5) Merge overlapping intervals 
5) Count increasing subarrays (gfg)
6) Remove duplicates in sorted array - 1 - keep start=0 and end=1 and check if a[start] == a[end]. If both are equal then increment the end. If not a[start] = a[end]
7) Remove Duplicates from Sorted Array II  - Find the difference between and first and last occurrance of an element to calculate how many times an element exists in the array. So the other method could be lets say if we are position x, check for a[x-2] if both are equal then do not increment the starting index. Go on till we find a distinct element and then replace.
8) Sort colors (leetcode) - VERY VERY IMPORTANT (DUTCH NATIONAL FLAG ALGORITHM)
9) Partition array according to given pivot 
10) Merge sorted array - Sort from back of nums1 most optimised without any extra space
7) Max consecutive ones
8) Move zeros 
9) Apply Operations to an Array  - VERY IMPORTANT
10) Remove element
11) Lexogrophically smallest palindrome
12) Shortest Distance to a Character
13) 
14) Minimize maximum pair sum in array 
15) Maximum distance between pair of values
16) Find the Index of the First Occurrence in a String (leetcode)
17) Valid Trinagle (both the approaches)
18) Remove duplicate elements in sorted array 2
19) K diff pairs in an array
20) Append characters to make string subsequence 
21) Maximum Matching of players with trainers
22) watering plants (not exactly 2 pointers)
23) Watering plants-2 
24) Container with most water  - Move in a direction whose height is less. if height[start]<height[end] -> increment start and vice versa. if both equal then do start++ and end-- . Do not sort the array, we need to apply 2 pointers here on the non-sorted array.
25) Trapping rain water - 1
21) Rotate array (not exactly two pointers) - Reverse the entire array -> Reverse the first k elements -> Reverse the next remaining n-k elements.

Not 2 pointers:
1) Next greater element - III
2) Next permutation
3) DI string match





