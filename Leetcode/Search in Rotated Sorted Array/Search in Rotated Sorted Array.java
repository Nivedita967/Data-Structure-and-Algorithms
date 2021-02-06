class Solution {
    public int search(int[] nums, int target) {
        int lo=0;
        int hi=nums.length-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(nums[mid]<nums[hi]){
                hi= mid;
            }
            else{
                lo= mid+1;
            }
        }
        int root= lo; 
        
        if(target>=nums[0] && root!=0){
            hi= root-1;
            lo= 0;
        }
        else{
            lo= root;
            hi= nums.length-1;
        }
        
        
         while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>target){
                hi= mid-1;
            }
            else if (nums[mid]<target){
                lo= mid+1;
            }
            else{
                return mid;
            }
            
        }
        return -1;
    }
}