class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) 
    {
        /*
        we need to start 
        */
        int n = a.size();
        int ans = 0;
        int start = -1;
        int next_to_take=0;
        /*if the array is sorted then we can use start and end and condition start<end in the while loop*/
        while(start<n and next_to_take<n)
        {
            if(a[next_to_take]==1)
            {
                ans = max(ans , next_to_take - start);
                next_to_take++;
            }
            else
            {
                start = next_to_take;
                next_to_take++;
            }
        }
        return ans;
    }
};
