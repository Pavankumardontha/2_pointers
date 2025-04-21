class Solution {
public:
    int minSwaps(string s) 
    {
        /*
        To make the binary string alternating , you need to either start with '0' or '1'
        We will calculate the moves in both the cases and take the minimum of both.
        If no of 0's = c0 and no. of 1's = c1
        then |c0-c1|<=1 to make the string alternating.
        
        */
        int n = s.length();
        int c0=0;
        int c1=0;
        int i=0;
        while(i<n)
        {
            if(s[i] == '0')
            c0++;
            else
            c1++;
            i++;
        }
        if(abs(c1-c0)>1)
        return -1;
        else
        {
            i=0;
            if(c0>c1)
            {
                // '0' will be first and in even positions
                // example : 0110100 -> ans = 2 -> 0101010
                // swap -> (2,3) -> 0101100
                // swap -> (4,5) -> 0101010
                int ans = 0;
                while(i<n)
                {
                    // so if '1' is in even positions , we need a swap
                    if(s[i]=='1')
                    {
                        ans++;
                    }
                    i=i+2;
                }
                return ans;
            }
            else if(c1>c0)
            {
                // '1' will be first and in even positions
                int ans=0;
                while(i<n)
                {
                    // so if '0' is in even positions , we need a swap
                    if(s[i]=='0')
                    {
                        ans++;
                    }
                    i=i+2;
                }
                return ans;
            }
            else
            {
                // anything can be first we need to return the minimum of both the answers computed taking '0' as first and '1' as first
                int ans1 = 0;
                int ans2 = 0;
                while(i<n)
                {
                    if(s[i] == '0')
                    {
                        // assuming '1' is first element and is that even locations
                        ans1++;
                    }
                    else
                    ans2++;
                    i=i+2;
                }
                return min(ans1,ans2);
            }
        }
        
    }
};
