/* Approach - 1 : Fixing the smallest element and iterating on the rest. This approach will not work since we will have conditions in which we cannot 
exactly tell whether to increment start or decrement end variable.*/
class Solution {
public:
    int triangleNumber(vector<int>& a) 
    {
        /* NOTE:- Here the combinations can be repeated.*/
        sort(a.begin(),a.end());
        int n = a.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            /* 
            we will fix i and find for a pair (j,k) in the range [i+1.n-1] such that j+k>i to 
            satisfy triangle property 
            */
            int start = i + 1;
            int end = n-1;
            while(start<end)
            {
                if(a[i] + a[start] > a[end])
                {
                    /*
                    there should be 3 conditions satisfying simultaneously 
                    1) a[start] + a[end] > a[i]
                    2) a[i] + a[start] > a[end]
                    3) a[i] + a[end] > a[start]

                    out of the 3 conditions , since the array is sorted and i < start < end implies that
                    a[i]<=a[start]<=a[end]
                    so condition 1) and condition 3) are always satisfied in our case. We are left only 
                    with condition 3.
                    
                    Lets say we got the pair
                    Ex : 2   3    4   4 
                         i  start    end  
                    if (3,4) forms a valid pair , then this implies that any number x which is 
                    present between 3 and 4 will also form a valid pair with 4. 
                    so if (start,end) is a valid pair , then any number x present between the start and the 
                    end forms a valid pair with end !!!!
                    so if (start,end) is valid then (x,end) is also valid where start<x<end
                    */
                    ans = ans + (end-start);
                    start++; // its not quite obvious here to either decrement end or increment start !!!
                }
                else
                {
                    /*
                    if k <= a[i] , its quite obvious that we need to move start since we have to increase k
                    */
                    end--;
                }
            }
        }
        return ans;
    }
};



/* Approach-2 : We fix the largest element here and try to search for the pair of smaller elements. This case works out since in each condition , we know
exactly where to increment the start and decrement the end variables.*/

class Solution {
public:
    int triangleNumber(vector<int>& a) 
    {
        int n = a.size();
        sort(a.begin(),a.end());
        int ans = 0;
        // fixing the larger element and searching for smaller element pair 
        for(int i=2;i<n;i++)
        {
            int start = 0;
            int end = i-1;
            while(start < end )
            {
                if(a[start] + a[end] > a[i])
                {
                    /* Important difference to note here is that both start and end are on the same side of 
                    the equation which are not the case in the previous situation */
                    ans = ans + (end-start);
                    end--;
                }
                else
                start++;
            }
        }
        return ans;
    }
};



