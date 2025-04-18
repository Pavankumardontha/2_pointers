class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        int n1 = str1.length();
        int n2 = str2.length();
        int start = 0; // index to track the elements in str2
        char c;
        for(int i=0;i<n1;i++)
        {
            if(str1[i] == str2[start])
            start++;
            else
            {
                // once convert str1[i] and see if it equals to str2[start]
                c = 'a' + ( (str1[i] - 'a' + 1) % 26 );
                if(c == str2[start])
                start++;
            }
            if(start == n2)
            return true;
        }
        return false;
    }
};
