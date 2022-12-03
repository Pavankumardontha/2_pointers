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
