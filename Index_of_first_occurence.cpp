// Find the Index of the First Occurrence in a String (leetcode)

class Solution {
public:
    int strStr(string s1, string s2) 
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int ind1 = 0; // index to iterate on s1
        int ind2 = 0; // index to iterate on s2
        int start_index = 0; // first index in s1 which matches with first index in s2
        while(ind1<n1 and ind2<n2)
        {
            if(s1[ind1]==s2[ind2])
            {
                if(ind2==0)
                {
                    // index of s1 matching with fist character in s2
                    start_index=ind1;
                }
                ind1++;
                ind2++;
            }
            else
            {
                if(ind2 == 0)
                ind1++;
                else
                {
                    /* once we have a mismatch after traversing some characters of s2 , we need to start
                    traversing s2 from the start which is obvious and we need to start traversing s1 from 
                    start_index + 1. This is important !!!
                    */ 
                    ind1 = start_index + 1;
                    ind2 = 0;
                }
            }
        }
        if(ind2==n2)
        return ind1 - n2;
        else
        return -1;
        
    }
};
