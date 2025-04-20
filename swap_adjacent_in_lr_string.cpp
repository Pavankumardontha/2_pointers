class Solution {
public:
    bool canTransform(string start, string target) 
    {
        // do move pieces to obtain a string
        int n = start.length();
        string s1,s2;
        s1.reserve(n);
        s2.reserve(n);
        int i=0;
        while(i<n)
        {
            if(start[i] == 'L' or start[i] == 'R')
            s1 +=start[i];
            if(target[i] == 'L' or target[i] == 'R')
            s2 +=target[i];
            i++;
        }
        if(s1 != s2)
        return false;
        else
        {
            i=0;
            int j=0;
            while(i<n and j<n)
            {
                while(start[i] == 'X')
                i++;
                while(target[j] == 'X')
                j++;

                if(start[i] == 'L')
                {
                    if(i<j)
                    return false;
                }
                else
                {
                    if(i>j)
                    return false;
                }
                i++;
                j++;
            }
            return true;
        }
    }
};
