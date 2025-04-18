class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        int n = s.length();
        /*
        D = "decreasing" from length value
        I = "Increasing" from 0 value
        */
        vector<int> ans(n+1);
        int i = 0;
        int start = -1;
        int end = n+1;
        while(i<n)
        {
            if(s[i] == 'I')
            {
                start++;
                ans[i]=start;
            }
            else
            {
                end--;
                ans[i]=end;
            }
            i++;
        }
        if(s[n-1]=='I')
        {
            start++;
            ans[n]=start;
        }
        else
        {
            end--;
            ans[n]=end;
        }
        return ans;
    }
};
