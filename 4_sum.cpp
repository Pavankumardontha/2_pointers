class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) 
    {
        /*
        In 3 sum problem we have fixed c, same like there here we will fix 2 variables (c,d) and start
        searching for (a,b) pair using two pointers.
        */
        int n = a.size();
        vector<vector<int>> ans;
        if(n<4)
        return ans;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            /* to avoid duplicates */
            if(i!=0 and a[i]==a[i-1])
            continue;
            for(int j=i+1;j<n;j++)
            {
                /* to avoid duplicates */
                if(j!=i+1 and a[j]==a[j-1])
                continue;

                /* now we have fixed (c,d) and we will now look out for (a,b) in the range [j+1,n-1] using
                2 pointers technique */
                int start = j+1;
                int end = n-1;
                while(start < end)
                {
                    long long int k = a[start] + a[end];
                    long long int required_sum = (long long)target - a[i] - a[j];
                    if(k == required_sum)
                    {
                        /* we have got our combination */
                        vector<int> choices;
                        choices.push_back(a[i]);
                        choices.push_back(a[j]);
                        choices.push_back(a[start]);
                        choices.push_back(a[end]);
                        ans.push_back(choices);
                        while(start+1<n and a[start]==a[start+1])
                        start++;
                        while(end-1>=0 and a[end-1]==a[end])
                        end--;
                        start++;
                        end--;
                    }
                    else if(k < required_sum)
                    {
                        while(start+1<n and a[start]==a[start+1])
                        start++;
                        start++;
                    }
                    else
                    {
                        while(end-1>=0 and a[end-1]==a[end])
                        end--;
                        end--;
                    }
                }

            }
        }
        return ans;
        
    }
};
