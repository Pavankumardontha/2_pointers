// we need not check if both s and target length are different. Its already given that both are equal
        /*
        Observations:
        1) The order of both the strings after removing '_' characters must be same.
        For example: start = "_L__R__R_", target = "L______RR"
        In both the strings the order is "LRR"
        if the order is not same , then start string cannot be converted into target string
        2) Lets take the example of start = "_R" and target = "R_". Here both the strings are same after removing the '_'
        characters from them. But start string CANNOT be converted into target string.
        lets take another example
        start = L__LR_RL__R , target = L_L_RR_L_R_
        for both the strings the strings after removing '_' characters is "LLRRLR" but still start cannot be converted into target
        lets see why 
        Now lets take the strings with indicex
        start = L__LR_RL__R , target = L_L_RR_L_R_
                012345678910           012345678910
        
        the first L index in target occurs at index 0 and also occurs at the same index in start 
        second L index at 2 in target and 3 in start (3>2) -> so we can move L present at index 3 in start to index 2 to make it equal to target 
        first R index at (4,4)
        second R index at (6,5) -> here we cannot move 'R' present at index 6 in start string to index 5 in target string. So start string cannot be converted
        into target string.
        */

class Solution {
public:
    bool canChange(string start, string target) 
    {
        int n = start.length();
        // we need not check if both s and target length are different. Its already given that both are equal
        string s1,s2;
        s1.reserve(n); // this is to allocate string of size n
        s2.reserve(n);
        int i=0;
        while(i<n)
        {
            if(start[i] == 'L' or start[i] == 'R')
            s1 += start[i];
            if(target[i] == 'L' or target[i] == 'R')
            s2 += target[i];
            i++;
        }
        if(s1 != s2)
        return false;
        else
        {
            i = 0; // iterates on start string
            int j = 0; // iterates on target string
            while(i<n and j<n)
            {
                while(start[i] == '_')
                i++;
                while(target[j] == '_')
                j++;

                if(i==n or j==n)
                break;

                cout<<i<<" "<<j<<endl;
                // both start[i] and target[j] will be same since the order of characters in both the strings are same. We have already verified this.
                if(start[i] == 'R')
                {
                    if(i>j)
                    {
                        // we can move R only to the right. so the index of 'R' in start must always be less than equal to index of 'R' in target
                        return false;
                    }
                }
                else
                {
                    // start[i] == 'L'
                    if(i<j)
                    {
                        // we can move L to the left. So the index of 'L' in start must always be greater than equal to the index of 'L' in target
                        return false;
                    }
                }
                i++;
                j++;
            }
            return true;
        }
    }
};
