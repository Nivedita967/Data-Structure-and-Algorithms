class NumArray {
public:
    //Declaring dp vector outside so it is accessible to both methods
    vector<int> dp;
    NumArray(vector<int>& nums) {
        //Finding the size of given array
        int size= nums.size();
        //For 0 elements... sum is 0
        dp.push_back(0);
        //Looping from 1 to n to find sum till i elements
        for(int i=1;i<=size;i++){
          dp.push_back(dp[i-1]+ nums[i-1]);
        }
    }
    
    int sumRange(int i, int j) {
        //Returning the difference between sum of j elements and sum of i elements to find answer
        return dp[j+1]- dp[i];
    }
};
