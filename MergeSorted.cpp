class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        /*
        Since nums1 have 0's at the end, we will start to sort things from the end.
        By this , we do not need any extra array to sort and so 
        Time complexity = O(n+m) and space complexity = O(1)

        Example-1 : nums1 = [1,2,3,0,0,0] , nums2 = [2,5,6]
        1) nums1 = [1,2,3,0,0,0] , nums2 = [2,5,6]
        last_zero_index_of_num1s = 5
        i=2
        j=2
        nums1[2] (3) < nums2[2] (6) -> nums2[j] comes before nums1[i] -> decrement j and go forward
        nums1 = [1,2,3,0,0,6] , nums2 = [2,5,6]

        2) i=2 , j = 1 , last_zero_index_of_nums1 = 4;
        nums1[2] (3) < nums2[j] (5) -> decrement j and go forward
        nums1 = [1,2,3,0,5,6] , nums2 = [2,5,6]

        3) i=2 , j=0 , last_zero_index_of_nums1 = 3
        num1[i] (3) > nums2[j] (2) -> decrement i and go forward
        nums1 = [1,2,3,3,5,6] , nums2 = [2,5,6]

        4) i=1 , j = 0 , last_zero_index_of_nums1 = 2 (there is no 0 practically at nums1[2] though)
        nums1[i] (2) == nums2[j] -> we can decrement any and move forward -> decrementing j here
        nums1 = [1,2,2,3,5,6] , nums2 = [2,5,6]

        5) i=1 , j= -1 , last_zero_index_of_nums1 = 1 but loop ends here and we got the correct order 
        stored in nums1 array


        example-2 : nums1 = [4,5,6,0,0,0] nums2 = [1,2,3]
        1) i = 2 , j= 2 , last_zero_index_of_nums1 = 5
        .
        .
        if we run this , we get finally 
        i = -1 , j=2 , last_zero_index_of_nums1 = 2
        nums1 = [4,5,6,4,5,6] and nums2 = [1,2,3]

        we now start adding nums2 from the jth index using the last_zero_index_of_nums1
        */

        int last_zero_index_of_nums1 = n+m-1; // last index of nums1 will be the last index holding 0
        int i=m-1; // last_non_zero_element_of_nums1
        int j=n-1;
        while(i>=0 and j>=0)
        {
            if(nums1[i] >= nums2[j])
            {
                // num1[i] will come later than nums[j] 
                nums1[last_zero_index_of_nums1] = nums1[i];
                i--;
            }
            else
            {
                // nums2[j] will come later than nums1[i]
                nums1[last_zero_index_of_nums1] = nums2[j];
                j--;
            }
            last_zero_index_of_nums1--;
        }
        while(j>=0)
        {
            nums1[last_zero_index_of_nums1] = nums2[j];
            j--;
            last_zero_index_of_nums1--;
        }
    }
};






/* APPROACH-2 With extra space */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int first_index = 0;
        int second_index = 0;
        int index = 0;
        vector<int> ans;
        while(first_index < m and second_index < n)
        {
            if(nums1[first_index] < nums2[second_index] )
            {
                ans.push_back(nums1[first_index]);
                first_index++;
            }
            else
            {
                ans.push_back(nums2[second_index]);
                second_index++;
            }
        }
        while(first_index<m)
        {
            ans.push_back(nums1[first_index]);
            first_index++;
        }
        while(second_index<n)
        {
            ans.push_back(nums2[second_index]);
            second_index++;
        }
        for(int i=0;i<ans.size();i++)
        nums1[i]=ans[i];
        
    }
};
