class Solution {
public:
    int minimumRefill(vector<int>& p, int capacityA, int capacityB) 
    {
        int n = p.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        int current_capacity_a = capacityA;
        int current_capacity_b = capacityB;
        /*
        At each step we water at both l and r. 
        if l != r then l will be watered by alice and r will be watered by bob
        if l ==r then alice will water if he has enough if not bob will water
        */
        while(l<=r)
        {
            if(l==r)
            {
                if(current_capacity_a >= current_capacity_b)
                {
                    // alice should water the plant
                    if(current_capacity_a >= p[l])
                    current_capacity_a = current_capacity_a - p[l];
                    else
                    {
                        current_capacity_a = capacityA - p[l];
                        ans++;
                    }
                }
                else
                {
                    // bob should water the plant
                    if(current_capacity_b >= p[l])
                    current_capacity_b = current_capacity_b - p[l];
                    else
                    {
                        current_capacity_b = capacityB - p[l];
                        ans++;
                    }
                }
            }
            else
            {
                /* l will be watered by alice and r will be watered by bob */
                // water l by alice
                if(current_capacity_a >= p[l])
                current_capacity_a = current_capacity_a - p[l];
                else
                {
                    current_capacity_a = capacityA - p[l];
                    ans++; // increment if we are refilling
                }

                // water r by bob
                if(current_capacity_b >= p[r])
                current_capacity_b = current_capacity_b - p[r];
                else
                {
                    current_capacity_b = capacityB - p[r];
                    ans++;
                }
            }
            l++;
            r--;
        }
        return ans;
    }
};
