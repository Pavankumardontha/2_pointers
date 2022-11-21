class Solution {
public:
    int minPairSum(vector<int>& a) 
    {
        int n = a.size();
        sort(a.begin(),a.end());
        int ans = 0;
        int start=0;
        int end = n-1;
        while(start<end)
        {
            ans = max(ans,a[start]+a[end]);
            start++;
            end--;
        }
        return ans;
    }
};
