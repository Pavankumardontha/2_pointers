class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) 
    {
        int n = a.size();
        int start = 0;
        int end = n-1;
        while(start<end)
        {
            /*
            4 cases come up
            1) start - even , end - odd -> start++ 
            2) start - even , end - even -> start++
            3) start - odd , end - odd -> end--
            4) start - odd , end - even -> swap elements at index start and end and do start++ and end--
            */
            if(a[start]%2 == 0 and a[end]%2 == 1)
            start++;
            else if(a[start]%2 == 0 and a[end]%2 == 0)
            start++;
            else if(a[start]%2 == 1 and a[end]%2 == 1)
            end--;
            else
            {
                // a[start]%2 !=0 and a[end]%2 == 0
                cout<<a[start]<<" "<<a[end]<<endl;
                int temp = a[start];
                a[start] = a[end];
                a[end] = temp;
                start++;
                end--;
            }
        }
        return a;
    }
};
