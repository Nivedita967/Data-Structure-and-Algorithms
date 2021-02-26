/*
If the next term is getter than target then that i-th position is the answer
Incase array ended will all the terms less than our target number, in that 
case we will return back array size as the last location
*/
int searchInsert(int* nums, int numsSize, int target)
{
    for(int i=0; i<numsSize;i++)
    {
        if(target<=nums[i])
            return i;
    }
    return numsSize;
}
