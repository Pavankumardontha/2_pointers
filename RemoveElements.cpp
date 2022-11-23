class Solution {
public:
    int removeElement(vector<int>& a, int target) 
    {
        int n = a.size();
        int next_to_check = 0;
        int next_to_update = 0;
        while(next_to_check < n)
        {
            if(a[next_to_check]!=target)
            {
                /* we need to store this element */
                a[next_to_update] = a[next_to_check];
                next_to_update++;
                next_to_check++;
            }
            else
            next_to_check++;
        }
        return next_to_update;
        
    }
};
