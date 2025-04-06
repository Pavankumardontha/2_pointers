# Problems
1) Count pairs with given sum (gfg not exactly 2 pointers)
2) Minimum window substring (leetcode)

# purely 2 pointer problem and quite obvious
1) 2 sum - 1 (leetcode)
2) 2 sum - 2 (leetcode)
3) 3 sum (leetcode) -> Run outerloop for 1st element and search the other 2 elements using 2 pointers method. We need to eliminate duplicates at the outer loop and also inside the 2 pointer method.
4) 4 sum (leetcode) -> Run outerloops for 1st and 2nd elements. Find 3rd and 4th using 2 pointers method. Handle the duplicate condition at the ith loop , jth loop and also inside the 2 pointers method.
5) 3 sum closest (leetcode) -> same like 3 sum . Calculate the sum and if sum<target -> start++ or end--. Always store the closest sum to the given target in some variable and compare for each case.
6) Merge Two 2D Arrays by Summing Values (leetcode)
7) Sort Array By Parity (leetcode)
8) Sort array by parity - 2 (leetcode) - Here take 2 pointers starting with an even and odd index and increment them by 2 till the condition is met. Swap the elements at the
   point of condition failure.
9) Rearrange Array Elements by Sign (leetcode) - CANNOT BE SOLVED IN-PLACE. Should use extra space and its easy to solve.
5) Merge overlapping intervals (leetcode)
5) Count increasing subarrays (gfg)
6) Remove duplicates in sorted array (leetcode) 
7) Merge sorted array (leetcode) - Sort from back of nums1 most optimised without any extra space
7) Max consecutive ones (leetcode)
8) Move zeros (leetcode)
9) Remove elements (leetcode)
10) Minimize maximum pair sum in array (leetcode) 
11) Maximum distance between pair of values (leetcode)
12) Find the Index of the First Occurrence in a String (leetcode)
13) Valid Trinagle (both the approaches - leetcode)
15) Remove duplicate elements in sorted array 2 (leetcode)
16) K diff pairs in an array (leetcode)
17) Append characters to make string subsequence (leetcode) 
18) Maximum Matching of players with trainers (leetcode)
19) watering plants (leetcode - not exactly 2 pointers)
20) Watering plants-2 (leetcode)
21) Container with most water (leetcode) - Move in a direction whose height is less. if height[start]<height[end] -> increment start and vice versa. if both equal then do start++ and end-- . Do not sort the array, we need to apply 2 pointers here on the non-sorted array.
22) Trapping rain water - 1 (leetcode)
21) Rotate array (not exactly two pointers leetcode)






