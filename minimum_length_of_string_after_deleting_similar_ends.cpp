class Solution {
public:
    int minimumLength(string s) 
    {
        int n = s.length();
        int start = 0;
        int end = n-1;
        char c;
        while(start<end)
        {
            if(s[start] != s[end])
            return end-start+1;
            else
            {
                c = s[start];
                while(start<n and s[start]==c)
                start++;
                while(end>=0 and s[end] == c)
                end--;

            }
        }
        /*
        after the above loop ends. There are only 2 possibilities
        -> either start == end or 
        -> start and end might have crossed each other
        if they have crossed then we return zero and if both are equal then we need to return 1
        */
        if(start == end)
        return end-start + 1;
        else
        return 0;
    }
};
