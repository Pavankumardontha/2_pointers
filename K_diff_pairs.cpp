class Solution {
public:
    int findPairs(vector<int>& a, int k) 
    {
        sort(a.begin(),a.end());
        int n = a.size();
        int start=0;
        int end=1;
        int answer = 0;

        /*
        Note the difference here , even when we have sorted the array, we are traversing in only one 
        direction . Both start and end variables will always increment instead of end variable starting 
        from the end and decrementing. 
        */
        while(start<n and end<n)
        {
            /*
            To avoid one element being added in the same pair twice , we need to ensure always that start 
            and end variables are never equal and always end is more than start.
            */
            if(a[end]-a[start] == k)
            {
                answer = answer + 1;
                start++;
                // deleteing duplicates
                while(start<n and a[start-1]==a[start])
                start++;

                // ensuring end is always greater than start
                if(end<=start)
                end = start + 1;
            }
            else if(a[end]-a[start]<k)
                end++;
            else
            {
                start++;
                // ensuring end is always greater than start
                if(end<=start)
                end = start + 1;
            }
        }
        return answer;
    }
};
