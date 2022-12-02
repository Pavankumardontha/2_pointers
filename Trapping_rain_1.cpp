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
