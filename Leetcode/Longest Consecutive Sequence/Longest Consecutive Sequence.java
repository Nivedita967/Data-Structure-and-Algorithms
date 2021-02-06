class Solution {
    public int longestConsecutive(int[] nums) {
       HashSet<Integer> s= new HashSet<Integer>();
        int ans=0;
        for( int i=0; i<nums.length; i++)
            s.add(nums[i]);
        for( int i=0; i<nums.length; i++){
            if(!s.contains(nums[i]-1)){
                int j=nums[i];
                while(s.contains(j))
                    j++;
                if(ans<j-nums[i])
                    ans=j-nums[i];
            }
        }
        return ans;
    }
}