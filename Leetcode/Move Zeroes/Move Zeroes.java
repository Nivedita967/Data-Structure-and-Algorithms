// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
class Solution {
    public void moveZeroes(int[] nums) {
        int countZeroes = 0;
        int nonZeroIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) { // if it is a zero
                countZeroes++; // increase count of zeroes
            }
            else {
                nums[nonZeroIndex] = nums[i];
                nonZeroIndex++; // it is not a zero, so move to the next number
            }
        } // starting at end, make them all 0s for the  number of 0s encountered. 
        for (int i = nums.length - 1; countZeroes > 0; i--) { 
            nums[i] = 0;
            countZeroes--;
        }
       }
 }