class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
        int n = s.length();
        vector<int> ans(n,0);
        int start = 0;
        int l = -1; // nearest index to the left of current index where s[l] = c
        int r = -1; // nearest index to the right of current index where s[r] = c
        while(start<n)
        {
            if(r<start)
            {
                l = r;
                r++;
                while(r<n and s[r] != c)
                r++;
            }
            else
            {
                if(l<0) // there is no index l present to the left of current index where s[l] = c
                ans[start] = abs(start-r);
                else if(r==n) // there is no index r present to the right of current index where s[r]=c
                ans[start] = abs(start-l);
                else
                ans[start] = min(abs(start-l),abs(start-r)); // both left index and right index are present such that s[l]=s[r]=c
                start++;
            }
        }
        return ans;
    }
};
