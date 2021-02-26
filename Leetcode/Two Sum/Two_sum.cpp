

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        //calculating the size of vector
        int n=nums.size();

        //declaration of vector for storing indexes
        vector<int> index;

        //loop for checking the indexes whose elements add up to target value
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    // pushing the indexes 
                    index.push_back(i);
                    index.push_back(j);
                }
            }
         }
        
        return index;
        
    }
};