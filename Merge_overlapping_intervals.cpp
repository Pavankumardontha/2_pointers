
bool comp(vector<int> a ,vector<int> b)
{
    if(a[0]<b[0])
    return true;
    else if(b[0]<a[0])
    return false;
    else
    {
        if(a[1]<b[1])
        return true;
        else
        return false;
    }
    return true; // if a[0]==b[0] and a[1]==b[1]
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),comp);

        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(start<=intervals[i][0] and intervals[i][0]<=end)
            {
                // merge the interval
                if(end<intervals[i][1])
                end = intervals[i][1];
            }
            else 
            {
                // insert start and end into the ans
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> temp1;
        temp1.push_back(start);
        temp1.push_back(end);
        ans.push_back(temp1);
        return ans;
    }
};
