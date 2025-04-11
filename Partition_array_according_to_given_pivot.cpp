
/* APPROACH-1 WILL NOT WORK */

class Solution {
public:

    void reverse_elements(vector<int> &nums , int l , int r)
    {
        int n = nums.size();
        int start = l;
        int end = r;
        while(start>=0 and start<n and end>=0 and end<n and start<=end)
        {
            swap(nums[start],nums[end]);
            end--;
            start++;
        }
    }
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        /*
        Input: nums = [9,12,5,10,14,3,10], pivot = 10
        Output: [9,5,3,10,10,12,14]

        Imagine we do a dutch national flag algorithm , we get the end result has
        [9,5,3,10,10,14,12]
        Now notice the elements after the pivot. They are not in the same order has they appeared in the array. To make them in the same order,
        we need to reverse the elements which are  greater than the pivot.

        Take another input 
        nums = [19,15,12,-14,8,-7,-11] , pivot = -7
        output  [-14,-11,-7,19,15,12,8]
        But if we use our algorithm by reversing the elements after the pivot , we still do not get the correct answer. According to our algorithm , the output is 
        [-11,-14,-7,19,15,12,8]
        But its wrong since -14 should come before -11 in the final answer because we need to maintain the same order as present in the input array.

        We are sure that elements which come after pivot do come in reverse order and if we reverse that part of the array , this problem gets solved. 
        But what about the elements smaller than pivot ? Do they come in reverse order or straight order ? we will not know this and it depends on the situation.
        So if we do not want the order of elements to be preserved then we do not need any extra space and also the dutch national algorithm works well like in the case of sorting 0's 1's and 2's.
        So the solution here is to use extra space !! cannot be done in O(1) time complexity 
        */
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid<=high)
        {
            if(nums[mid] == pivot)
            mid++;
            else if(nums[mid]<pivot)
            {
                swap(nums[mid],nums[low]);
                // after this step , we are sure that the element present at index low is less than the element present at index mid
                low++;
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }

        /*
        reverse the elements in the array which are greater than the pivot.
        [1,2,3,4] -> after reversal [4,3,2,1]
        */
        reverse_elements(nums,high+1,n-1);
        return nums;
    }
};


/* APPROACH -2 with extra space . This will work */
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        /* Run 3 loops to place the elements less than pivot , pivot elements and elements greater than pivot */
        int n = nums.size();
        vector<int> result(n);
        int start = 0;
        int end = n-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i] < pivot)
            {
                result[start]=nums[i];
                start++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i] == pivot)
            {
                result[start] = nums[i];
                start++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]>pivot)
            {
                result[start]=nums[i];
                start++;
            }
        }
        return result;
    }
};
