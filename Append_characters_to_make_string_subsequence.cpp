class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        int i = 0;
        int j = 0;
        int n1 = s.length();
        int n2 = t.length();
        while(i<n1 and j<n2)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            i++;
        }
        return n2-j;
    }
};
