/* TODO : To return the number of arithmetic subarrays of nums 
We observe that we only need to keep the track of the last element to 
we check if the ith element satsfies the common difference criteria with the previous element. 
If so, we know the number of new arithmetic slices added will be 1+ previous element 
The count is also updated by the same count to reflect the new arithmetic slices */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        
        if(n<3){
            return 0;
        }
        
        int answer;
        int d=0;          //initialise the element as 0 
        
        for(int i=2;i<n;i++){
            if(nums[i-1]-nums[i-2] == nums[i]- nums[i-1]){     // check if difference of three consecutive elements is same 
                d = 1+d;
                answer+=d;
            }
            else{
                d=0;
            }
        }
        return answer;
  }
};
