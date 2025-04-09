 /*
consider the example elements= 1,1,2,2,2,2,3,3
                        index= 0 1 2 3 4 5 6 7
notice the change in the from index 1->2 and from index 5->6. So we have encountered 2 changes and the solution revolves around finding these changes !! 
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int start = 0;
        int end = 1;

        while(start<n and end<n)
        {
            if(nums[end]==nums[start])
            end++;
            else
            {
                start++;
                nums[start] = nums[end];
                end++;
            }
        }
        return start+1;
    }
};
