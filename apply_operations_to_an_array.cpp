class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n = nums.size();
        int start = -1;
        int end = 0;
        /*
        NOTE: Before this question do 'Move zeros' leetcode question.
        we will increment start slowly and end will iterate in the normal pace.
        */
        while(start<n and end<n and end+1<n)
        {
            if(nums[end] != 0)
            {
                start++;
                if(nums[end] == nums[end+1])
                {
                    nums[start] = 2*nums[end];
                    nums[end+1] = 0;
                }
                else
                nums[start] = nums[end];
            }
            end++;
        }
        // we miss the last element of the array in this iteration since we have end+1<n
        if(nums[n-1] !=0)
        {
            start++;
            nums[start]=nums[n-1];
        }

        // we need to keep 0's from start+1 to the end of the array
        start++;
        while(start<n)
        {
            nums[start]=0;
            start++;
        }
        return nums;
    }
};
