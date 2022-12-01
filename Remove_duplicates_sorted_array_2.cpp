
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
