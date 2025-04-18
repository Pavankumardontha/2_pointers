class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size();
        int start = -1;
        int end = 0;
        int ans = 0;
        int repitition_count;
        string temp;
        int first_index=0; // index of first occurrance of a character
        while(end<n)
        {
            if(chars[first_index] == chars[end])
            end++;
            else
            {
                /* element at chars[first_index] is present from first_index index to end-1 index */
                repitition_count = (end-first_index);
                if(repitition_count>1)
                {
                    temp = to_string(repitition_count);
                    ans = ans + 1 + temp.length();
                    start++;
                    chars[start] = chars[first_index]; 
                    for(int i=0;i<temp.size();i++)
                    {
                        start++;
                        chars[start] = temp[i];
                    }
                }
                else
                {
                    ans = ans + 1;
                    start++;
                    chars[start] = chars[first_index];
                }
                first_index = end;
            }
        }
        repitition_count = end-first_index;
        if(repitition_count>1)
        {
            temp = to_string(repitition_count);
            ans = ans + 1 + temp.length();
            start++;
            chars[start] = chars[first_index]; 
            for(int i=0;i<temp.size();i++)
            {
                start++;
                chars[start] = temp[i];
            }
        }
        else
        {
            ans = ans + 1;
            start++;
            chars[start] = chars[first_index];
        }
        return ans;
    }
};
