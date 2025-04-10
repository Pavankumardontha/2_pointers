
/*
lets say that we represent the index_to_change as c and distinct_element_index with d.
Ex : 2,2,2,2,2,3,3,3,4
     0,1,2,3,4,5,6,7,8
1) c = 2 , d = 2 and a[c-2] = a[d] imples increment d
2) c = 2 , d = 3 same as above
3) c = 2 , d = 4 same as above
4) c = 2 , d = 5 and a[c-2] != a[d] and we have now got the distinct element so a[c] = a[d] and increment both so the array becomes 

2,2,3,2,2,3,3,3,4
0,1,2,3,4,5,6,7,8

5) c = 3, d = 6 and a[c-2]! = a[d] same like above 
2,2,3,3,2,3,3,3,4
0,1,2,3,4,5,6,7,8

6) c = 4 , d = 7 and a[c-2] = a[d] we will move forward and increment d

7) c = 4 , d = 8 and a[c-2] != a[d] we replace and increment both 

2,2,3,3,4,3,3,3,4
0,1,2,3,4,5,6,7,8

8) c = 5 and d = 8 and so the loop iteration ends and our answer is c=5. 
*/

class Solution {
public:
    int removeDuplicates(vector<int>& a) 
    {
        int n = a.size();
        if(n==1 or n==2)
        return n;
        int index_to_change = 2;
        int distinct_element_index = 2;
        while(distinct_element_index < n)
        {
            if(a[distinct_element_index] == a[index_to_change-2])
            {
                /*
                we did not get the distinct element and we need to go further to search for distinct element
                so that we can replace the element at index_to_change with distinct element.
                */
                distinct_element_index++; 
            }
            else
            {
                //we got the distinct element that we need to replace
                a[index_to_change] = a[distinct_element_index];
                distinct_element_index++;
                index_to_change++;
            }
        }
        return index_to_change;
    }
};



/* APPROACH-2 : 2 pointers */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        /*
        [2,3,3,3,3,4,4,4,4] -> correct ans = [2,3,3,4,4,4,4,4,4]
         0,1,2,3,4,5,6,7,8
        
        we start with start=0 and end=1 and we iterate end till we find the an index where a[start] != a[end]

        1) start=0 , end=1
        [2,3,3,3,3,4,4,4,4]
        start++ -> start=1 
        end=1

        2) start=1 , end=5 a[1] != a[5]
        so our array now becomes
        since end-start>=2 we have more than 2 duplicacy of element.
        start=start+2  -> start=1+2 = 3 
        a[start] = a[end]
        final array : [2,3,3,4,3,4,4,4,4]

        WE CANNOT MEASURE DUPLICACY JUST BY (end-start) !! follow the above case
        */
        int n = nums.size();
        int k = 1; // allowed duplicacy for each element in nums array
        int start = -1;
        int end = 0;
        int first_occurrance=0; // first occurance of new element index
        while(start<n and end<n)
        {
            while(end<n and nums[first_occurrance]==nums[end])
            end++;

            if(end-first_occurrance>=k)
            {
                for(int i=0;i<k;i++)
                {
                    start++;
                    nums[start] = nums[first_occurrance];
                }
            }
            else
            {
                for(int i=0;i<(end-first_occurrance);i++)
                {
                    start++;
                    nums[start] = nums[first_occurrance];
                }
            }
            first_occurrance = end;
        }
        return start+1; // since we need to return the size
    }
};






