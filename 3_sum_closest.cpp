class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int closest_sum = nums[0]+ nums[1]+nums[2]; // this is the answer
        int min_diff = INT_MAX; // overall minimum difference between the current sum and target
        for(int i=0;i<n-2;i++)
        {
            int start = i+1;
            int end = n-1;
            while(start < end)
            {
                int cur_sum = nums[i] + nums[start] + nums[end];
                int cur_diff = abs(target - cur_sum);
                if(cur_diff < min_diff)
                {
                    min_diff = cur_diff;
                    closest_sum = cur_sum;
                }
                if(cur_sum == target)
                return cur_sum;
                else if(cur_sum < target)
                start++;
                else
                end--;
            }
        }
        return closest_sum;
    }
};
