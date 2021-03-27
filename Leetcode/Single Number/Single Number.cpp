//simple bit manipulation question
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0; //initialize result to 0 to avoid garbage value
        for (int i = 0; i < nums.size(); i++){ //iterate through array
            result ^= nums[i]; //take xor of every number, xor of two same number results in 0 and hence the final result will be one occuring only once
        }
        return result;
    }
};