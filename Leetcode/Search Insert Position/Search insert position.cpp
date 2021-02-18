#include<vector>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        //calculating size of vector
        int count=nums.size();

        //loop for checking if any element is equal to target or not and returning output accordingly
       for(int i=0; i<count; i++)
       {
           if(nums[i]>=target)
           {
               return i;
           }
        }
        return count;
    }
};