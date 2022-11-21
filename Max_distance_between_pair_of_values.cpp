class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int ind1 = 0; 
        int ind2 = 0;
        int ans = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(ind1<n1  and ind2<n2)
        {
            if(ind1 > ind2)
            {
                /* ind2 must always be geater than or equal to ind1 */
                ind2++;
            }
            else if( nums1[ind1] > nums2[ind2])
            {
                /* we to decrease nums[ind1] and for that we need to  forward */
                ind1++;
            }
            else
            {
                /* 
                Come to the final else statement only after checking all the conditions before hand. By checking above 2 conditions we are confirm that
                a) ind1<=ind2 and 
                b) nums1[ind1]<=nums2[ind2]
                */
                ans = max(ans,ind2-ind1);
                ind2++;
            }
        }
        return ans;
    }
};
