class Solution {
public:
    void reverse(vector<int>& nums, int start,int end)
    {
        /*[2,3,4,5] -> [5,4,3,2]*/
        while(start<=end)
        {
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        /*
        Input: nums = [1,2,3,4,5,6,7], k = 3
        Output: [5,6,7,1,2,3,4]
        Explanation:
        rotate 1 steps to the right: [7,1,2,3,4,5,6]
        rotate 2 steps to the right: [6,7,1,2,3,4,5]
        rotate 3 steps to the right: [5,6,7,1,2,3,4]

        1) Reverse the Entire Array: reverse(0,n-1)
        2) Reverse the First k Elements: reverse(0,k-1)
        3) Reverse the remaining n-k elements: reverse(k,n-1)
        */

        int n = nums.size();
        k = k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);

    }
};
