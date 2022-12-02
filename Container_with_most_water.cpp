class Solution {
public:
    int maxArea(vector<int>& a) 
    {
        /* here 2 pointer technique is applied even if the array is not sorted !!! */
        int n = a.size();
        int start = 0;
        int end = n-1;
        int ans = INT_MIN;
        while(start<end)
        {
            ans = max(ans,(end-start)*min(a[start],a[end]));
            /* if a[start] is less then increment start and if a[end] is less then decrement end.*/
            if(a[start]>a[end])
            end--;
            else
            start++;
        }
        return ans;
    }
};
