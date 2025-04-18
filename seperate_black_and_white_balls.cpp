class Solution {
public:
    long long minimumSteps(string s) 
    {
        /* if the string is "1100"
        1100 -> 1010 -> 1001 -> 0101 -> 0011
                (1)      (2).    (3)    (4)

        so '1' present at index 0 will go to index 2 finally -> 2-0 = 2 swaps
        '1' present at index 1 will go to index 3 -> 3-1 = 2 swaps
        total = 2+2 = 4
        We can do the same with 0's too        
        */
        int n = s.length();
        int start = 0; // starting index of 0
        long long int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                ans = ans + i-start;
                start++;
            }
        }
        return ans;
    }
};
