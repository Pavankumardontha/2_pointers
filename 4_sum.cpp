class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            // handle duplicate cases for starting element a[i]
            if(i!=0 and nums[i] == nums[i-1])
            continue;

            for(int j=i+1;j<n-2;j++)
            {
                // handle duplicate cases for second element a[j]
                if(j!=i+1 and nums[j] == nums[j-1])
                continue;

                int start = j+1;
                int end = n-1;
                while(start<end)
                {
                    long long int cur_sum = 1LL*nums[i] + 1LL*nums[j] + 1LL*nums[start] + 1LL*nums[end]; // just to avoid overflow. We multiple int by 1LL to make long long int
                    if(cur_sum == target)
                    {
                        vector<int> temp = {nums[i],nums[j],nums[start],nums[end]};
                        ans.push_back(temp);
                        while(start+1<n and nums[start] == nums[start+1])
                        start++;
                        while(end-1>=0 and nums[end] == nums[end-1])
                        end--;
                        start++;
                        end--;
                    }
                    else if(cur_sum < target)
                    {
                        // we need to increment start to increase the cur_sum
                        while(start+1<n and nums[start] == nums[start+1])
                        start++;
                        start++;
                    }
                    else
                    {
                        while(end-1>=0 and nums[end] == nums[end-1])
                        end--;
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
