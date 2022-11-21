class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int current_index=0;
        int next_to_check = 0;
        int n = nums.size();
        while(next_to_check<n)
        {
            if(nums[next_to_check]!=0)
            {
                nums[current_index]=nums[next_to_check];
                current_index++;
                next_to_check++;
            }
            else
            next_to_check++;
        }
        //appending all zeros at the end 
        while(current_index<n)
        {
            nums[current_index]=0;
            current_index++;
        }
        
    }
};
