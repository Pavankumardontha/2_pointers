class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n = nums.size();
        int start=-1;
        int end=0;
        while(end<n)
        {
            if(nums[end] != val)
            {
                start++;
                nums[start] = nums[end];
            }
            end++;
        }
        return start+1;
    }
};
