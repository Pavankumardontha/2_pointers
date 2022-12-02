class Solution {
public:
    int trap(vector<int>& a) 
    {
        
        /*
        Water stored at index i = minimum(max element on left of i , max element on right of i) - a[i]
        */
        int n = a.size();
        int left_max[n],right_max[n];
        // left_max[i] stores the max element in the range [0,i]
        // right_max[i] stores the max element in the raneg [i,n-1]
        for(int i=0;i<n;i++)
        {
            if(i==0)
            left_max[i]=a[i];
            else
            left_max[i]=max(a[i],left_max[i-1]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            right_max[i]=a[i];
            else
            right_max[i]=max(a[i],right_max[i+1]);
        }
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            if(min(left_max[i-1],right_max[i+1])>=a[i])
            {
                // this is very important condition if not negative values will be added.
                ans = ans + min(left_max[i-1],right_max[i+1])-a[i];
            }
        }
        return ans;

    }
};


/* Approach - 2 : Using 2 pointers */
class Solution {
public:
    int trap(vector<int>& a) 
    {
        
        /*
        first do container with most water question and then come to this problem.
        In this problem also 2 pointer technique is applied even if the array is not sorted.
        */
        int n = a.size();
        int start = 0;
        int end = n - 1;
        /*we need to extra variables apart from start and end and these are left_max and right_max*/
        int left_max=0;
        int right_max=0;
        int ans = 0;
        while(start<end)
        {
            if(a[start]>a[end])
            {
                // we need to decrement end but before decrementing we need to compare with right_max
                if(a[end]>right_max)
                right_max = a[end];
                else
                ans = ans + (right_max - a[end]); // here is where the answer lies
                end--;
            }
            else
            {
                //we need to increment start but before incrementing we need to compare with left max
                if(a[start]>left_max)
                left_max = a[start];
                else
                ans = ans + (left_max - a[start]);
                start++;
            }
        }
        return ans;

    }
};
