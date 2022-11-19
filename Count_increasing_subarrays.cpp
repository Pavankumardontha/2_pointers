class Solution{
public:
	int countIncreasing(int a[], int n) 
	{
	    int start = 0;
	    int next_to_take = 1;
	    int ans = 0;
	    while(start < n and next_to_take < n)
	    {
	        if(a[next_to_take-1]<a[next_to_take])
	        {
	            ans = ans + (next_to_take - start);
	            next_to_take++;
	        }
	        else
	        {
	            start = next_to_take;
	            next_to_take++;
	        }
	    }
	    return ans;
	    
	}
};
