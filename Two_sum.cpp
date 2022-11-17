class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) 
    {
        int n = a.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        int start,end;
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-a[i])!=mp.end())
            {
                start = i;
                end = mp[target-a[i]];
                break;
            }
            mp[a[i]]=i;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
