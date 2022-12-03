class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> ans(n);
        /* element present at index i will move from i --> (i+k)%n index */
        for(int i=0;i<nums.size();i++)
        {
            int index = (i+k)%n;
            ans[index] = nums[i];
        }
        for(int i=0;i<n;i++)
        nums[i]=ans[i];
    }
};
