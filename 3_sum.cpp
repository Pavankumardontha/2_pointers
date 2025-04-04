/*
There are 3 methods to solve this problem 
a) brute force - O(N^3 * logN)
b) Hash map - O(N^2 * logN)
c) two pointers 
*/


/* Approach - 1 Brute force */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) 
    {
        /* brute force using 3 loops */
        set<vector<int>> st;
        int n = a.size();
        vector<vector<int>> ans;
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<i;j++)
            {
                for(int k=0;k<j;k++)
                {
                    if( a[i] + a[j] + a[k] == 0)
                    {
                        vector<int> choices;
                        choices.push_back(a[i]);
                        choices.push_back(a[j]);
                        choices.push_back(a[k]);
                        sort(choices.begin(),choices.end());
                        st.insert(choices);
                    }

                }
            }
        }
        for(auto& temp: st)
            ans.push_back(temp);
        return ans;  
    }
};

/* ----------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Appraoch - 2 Using hashmaps - O(N^2 * LogN) */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) 
    {
        set<vector<int>> st;
        int n = a.size();
        unordered_map<int,int> mp; // map to record frequencies of each element
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        mp[a[i]]++;
        for(int i=1;i<n;i++)
        {
            mp[a[i]]--; // very important step since we want to take each element only once
            for(int j=0;j<i;j++)
            {
                mp[a[j]]--; // removing one currence of a[i] 
                if(mp.find(-a[i]-a[j])!=mp.end() and mp[-a[i]-a[j]]!=0)
                {
                    /* if a + b + c = 0 imples c = -a - b 
                    so if there exists an element c (excluding a , b) then we can form a triplet 
                    */
                    vector<int> choices;
                    choices.push_back(a[i]);
                    choices.push_back(a[j]);
                    choices.push_back(-a[i]-a[j]);
                    sort(choices.begin(),choices.end());
                    st.insert(choices);
                }
                mp[a[j]]++; // inserting back one a[j]          
            }
            mp[a[i]]++; // inserting back a[i]
        }
        for(auto & temp : st)
        ans.push_back(temp);
        return ans;
        
    }
};

/*------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Approach - 3 two pointers very very important */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        /* 
            1.for applying 2 pointers , our array should be sorted.This is convinient case. Sometimes the array might not 
            also  be sorted and we can apply 2 pointers
            2. two pointers will only let you to find pair (a,b) consisting of 2 elements satisfying our constraints
            3. out of (a,b,c) we need to atleast fix one element and apply 2 pointers to search for other 2  
        */
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++)
        {
            /* if we fix c = a[i] , we will search for (a,b) in range (i,n-1) such that  a+b+c=0; 
            There are 2 places in which we need to handle the duplicate cases. 
            a) at the outer loop 
            b) inside the while loop of the 2 pointers
            */
            // handle duplicate cases
            if(i!=0 and nums[i] == nums[i-1])
            continue; 

            int start = i+1;
            int end = n-1;
            while(start<end)
            {
                int cur_sum = nums[i] + nums[start] + nums[end];
                if(cur_sum == 0)
                {
                    vector<int> temp = {nums[i],nums[start],nums[end]};
                    ans.push_back(temp);
                    // handling duplicate elements 
                    while(start+1<n and nums[start]==nums[start+1])
                    start++;
                    while(end-1>=0 and nums[end] == nums[end-1])
                    end--;
                    
                    start++;
                    end--;
                }
                else if(cur_sum < 0)
                {
                    // we need to increment start to increase the cur_sum 
                    // handling duplicates
                    while(start+1<n and nums[start+1]==nums[start])
                    start++;
                    
                    start++;
                }
                else
                {
                    // handling duplicates
                    while(end-1>=0 and nums[end] == nums[end-1])
                    end--;
                    
                    end--;
                }
            }
        }
        return ans;
    }
};
