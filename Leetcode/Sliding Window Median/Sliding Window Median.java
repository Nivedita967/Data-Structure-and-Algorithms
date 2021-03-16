class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        
        int n = nums.length; // Initialize n with the length of nums array
        double[] result = new double[n-k+1];
        List<Integer> list = new ArrayList<>(); // window list
        boolean isEven = (k % 2 == 0); 
        
        for (int i = 0; i < n; i++)
        {
            if (i >= k)
            {
                // Delete the head number from the window list
                int delPos = binarySearch(list, 0, list.size()-1, nums[i-k]);
                list.remove(delPos);
            }
            
            // Add the new number to the window list
            int addPos = binarySearch(list, 0, list.size()-1, nums[i]);
            list.add(addPos, nums[i]);
            
            // Check the condition
            if (i >= k-1)
            {
                if (isEven)
                    result[i-k+1] = ((double)list.get(k/2-1) + (double)list.get(k/2)) / 2.0;
                else
                    result[i-k+1] = (double)list.get(k/2);
            }
        }
        
        return result;
    }
    
    private int binarySearch(List<Integer> list, int left, int right, int target)
    {
        if (left <= right)
        {
            // calculate mid
            int mid = left + (right - left) / 2;
            int num = list.get(mid);
            
            // if num is equal to target
            if (num == target)
                return mid;
            else if (num < target)
                return binarySearch(list, mid+1, right, target);
            else
                return binarySearch(list, left, mid-1, target);
        }
        
        return left;
    }
}