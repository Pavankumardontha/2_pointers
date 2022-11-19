class Solution {
public:
    int removeDuplicates(vector<int>& a) 
    {
        int n =a.size();
        int next_to_take = 0;
        /*
        consider the example 
                elements= 1,1,2,2,2,2,3,3
                   index= 0 1 2 3 4 5 6 7

        notice the change in the from index 1->2 and from index 5->6. So we have encountered 2 changes
        and the solution revolves around finding these changes !! 
        */
        int index_to_change_next = 0;
        while(next_to_take<n)
        {
            if(next_to_take ==0 or a[next_to_take-1]!=a[next_to_take])
            {
                /* 
                condition - 1 : We need to always take the first element. 
                condition - 2 : if condition- 2 is satisfied , then element at next_to_take index is distinct. We need to store next_to_take 
                index element and store it at index_to_change_next index.
                */
                a[index_to_change_next]=a[next_to_take];
                index_to_change_next++;
                next_to_take++;
            }
            else 
            next_to_take++;
        }
        int no_of_distinct_elements = index_to_change_next;
        return no_of_distinct_elements;
    }
};
