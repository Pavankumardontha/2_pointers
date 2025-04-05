class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i=0;
        int j=0;
        vector<vector<int>> ans;
        while(i<n1 and j<n2)
        {
            if(nums1[i][0] == nums2[j][0])
            {
                vector<int> temp = {nums1[i][0],nums1[i][1] + nums2[j][1]};
                ans.push_back(temp);
                i++;
                j++;
            }
            else if(nums1[i][0] < nums2[j][0])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n2)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
};
