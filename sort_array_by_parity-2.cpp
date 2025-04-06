class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) 
    {
        /*
        Here both the pointers start from the front side of the array
        i = 0 (even index)
        j = 1 (odd index)
        we increment i and j both by 2. 
        if(a[i]%2 == 0) i+=2
        if(a[j]%2 == 1) j+=2
        we swap a[i] and a[j] when this condition fails.

        so i iterates only over even index and j iterates only over odd index

        example:-
        [4,2,7,5,9,6]
         0 1 2 3 4 5

        1) i=0 , j=1 
        increment i by 2 till it finds any odd element -> i = 2
        same goes with j. increment j by 2 till an even element is found -> j = 1
        swap(a[i],a[j]) -> [4,7,2,5,9,6]
                            0,1,2,3,4,5
        2) i=2,j=1
        repeat the same process 
        i=4 , j=5
        swap(a[i],a[j]) = swap(a[4],a[6]) -> [4,7,2,5,6,9] -> final output

        For every i which holds an odd element , there will be an equivalent j which holds an even element since
        the array contains equal number of odd and even elements as given in the question and so there will always
        be misplaced as pairs.

        Time : O(N)
        space : O(1) , we are doing inplace !!
        */
        int n = a.size();
        int i = 0;
        int j = 1;
        int temp;
        while(i<n and j<n)
        {
            while(i<n and a[i]%2==0)
            i+=2;
            while(j<n and a[j]%2==1)
            j+=2;

            if(i<n and j<n)
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
        return a;
    }
};
