class Solution {
    public int waysToMakeFair(int[] nums) {
        //Finding the size of given array
        int size= nums.length;
        //Declaring the answer
        int ans=0;
        //Now we will have two arrays. The left array is for all the elements that are yet to be processed and removed array is for all the elements that are already processed. We will further divide them based on if they are odd or even, and then we will maintain odd sum and even sum.
        int[] left= new int[2];
        int[] removed= new int[2];
        //Initially adding all the elements to left array
        for(int i=0;i<size;i++){
            left[i%2]+= nums[i];
        }
        //Processing each element
        for(int i=0;i<size;i++){
            left[i%2]-= nums[i];
            //After removing the current element, we are now checking if the even sum is equal to odd sum of all the other elements. Note that after removing the current element, the elements that come after that element will have their index parity changed
            if(left[0]+ removed[1]== left[1]+ removed[0]){
                ans++;
            }
            removed[i%2]+= nums[i];
        }
        return ans;
    }
}
