class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) 
    {
        sort(a.begin(),a.end());
        int n = a.size();
        int min_difference = INT_MAX; // minimum different between current sum and target
        int ans = a[0] + a[1] + a[2];
        for(int i=0;i<n;i++)
        {
            int start = i+1;
            int end = n-1;
            while(start<end)
            {
                int k = a[i] + a[start] + a[end]; // current sum 
                if(k==target)
                    return k;
                else if (k<target)
                {
                    /* 
                    we need to increase k so that we move close to the target and for that we need
                    start pointer 
                    */ 
                    if(min_difference > abs(target-k))
                    {
                        /*
                        if current difference which is abs(target-k) is less than min_difference we update
                        min_difference and answer
                        */
                        min_difference = abs(target-k);
                        ans = k;
                    }
                    start++;
                }
                else 
                {
                    /*
                    we need to decrement k so that we can move closer to the target 
                    */
                    if(min_difference > abs(target-k))
                    {
                        min_difference = abs(target-k);
                        ans = k;
                    }
                    end--;
                }
            }

        }
        return ans;
    }
};
