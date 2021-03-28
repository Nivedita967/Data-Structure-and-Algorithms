int findPeakElement(int* nums, int numsSize)
{
    if(numsSize == 1) //if only one element return index of that number
        return 0;
    if(nums[0] > nums[1])  //if first two numbers give the answer return that
        return 0;
    if(nums[numsSize-1] > nums[numsSize-2])  //similary, like above check last two
        return numsSize-1;
    for(int i=1;i<numsSize-1;++i) //iterate through the entire array
    {
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
        return i;
    }
    return;
}