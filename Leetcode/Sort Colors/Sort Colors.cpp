// Meth 1: Count the no. of Zeroes,ones and twoes.
//         Then a run a loop and print 0,1,2 respectively.
//         T.C. O(2*n)

// Meth 2: Use Dutch National Flag Algorithm
       
//        We are Using 3 pointers low,mid,high

//        if(nums[i]==0) : swap(a[mid],a[low]) then mid++,low++
//        if(nums[i]==1) : mid++
//        if(nums[i]==2) : swap(a[mid],a[high]) then high--


//        After this,
//         a[0....low-1] will have 0
//         a[low....mid] will have 1
//         a[high+1.....n] will have 2


//         T.C-O(n)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[low++],nums[mid++]);
                    break;
                    
                case 1:
                    mid++;
                    break;
                    
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
    }
};