class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) 
    {
        int n = a.size();
        int start = 0;
        int end = n - 1;
        vector<int> ans;
        while(start < end)
        {
            int k = a[start] + a[end];
            if(k==target)
            break;
            else if (k<target)
            start++;
            else
            end--;
        }
        ans.push_back(start+1);
        ans.push_back(end+1);
        return ans;
    }
};
