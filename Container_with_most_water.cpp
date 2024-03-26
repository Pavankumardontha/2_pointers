/*
    l=0
    r=n-1
    We start l from left and r from right. We find the minimum of (a[l],a[r]). if a[l] is
    less than a[r] , then the possible area is a[l]*(r-l+1). 
    Now we have to decide what to do in below 3 cases 
    1) a[l] < a[r]
    2) a[l] > a[r] 
    3) a[l] == a[r]
    ex : [6,8,5,9,7] 
          0 1 2 3 4
    initially l=0 , r=4 and a[0]<a[4]
    area = min(a[l],a[r])*(r-l) = min(6,7) * 4 = 24
    In this case , we increment i , in other words we eliminate the pairs 
    (6,9) , area = 6*3 = 18
    (6,5) , area = 5*2 = 10 
    (6,8) , area = 6*1 = 6
    So the max area is formed between (6,7) pair. 
    So if 
    1) a[l] < a[r] , we can surely tell that this is the max possible area formed by 
        using a[l] and so we need to increment l. 
    2) a[r] < a[l] , we can surely tell that this is the max possible area formed by 
        using a[r] and so we decrement r.
    3) a[l] == a[r] , we need to increment l and decrement r.
*/

class Solution {
public:
    int maxArea(vector<int>& a) 
    {
        int l=0;
        int r=a.size()-1;
        int ans = 0; 
        while(l<=r)
        {
            ans = max(ans,min(a[l],a[r])*(r-l));
            if(a[l]<a[r])
            l++;
            else if(a[r]<a[l])
            r--;
            else
            {
                l++;
                r--;
            }
        }
        return ans;
    }
};
