class Solution {
public:
    int minimumRefill(vector<int>& a, int capacityA, int capacityB) 
    {
        int n = a.size();
        if(n==1 or n==2)
        return 0;
        int start = 0;
        int end = n-1;
        int ans = 0;
        int current_capacity_a = capacityA;
        int current_capacity_b = capacityB;
        while(start<=end)
        {
            if(start==end)
            {
                if(current_capacity_a>=current_capacity_b)
                {
                    //alice should water the plant
                    if(current_capacity_a < a[start])
                    {
                        ans++;
                        start++;
                    }
                    else
                        start++;
                }
                else
                {
                    if(current_capacity_b < a[start])
                    {
                        ans++;
                        end--;
                    }
                    else
                        end--;
                }

            }
            else
            {
                if(current_capacity_a>=a[start])
                {
                    current_capacity_a = current_capacity_a - a[start];
                    start++;
                }
                else
                {
                    current_capacity_a = capacityA;
                    current_capacity_a = current_capacity_a - a[start];
                    start++;
                    ans++;
                }
                if(current_capacity_b>=a[end])
                {
                    current_capacity_b = current_capacity_b - a[end];
                    end--;
                }
                else
                {
                    current_capacity_b = capacityB;
                    current_capacity_b = current_capacity_b - a[end];
                    end--;
                    ans++;
                }

            }
        }
        return ans;  
    }
};
