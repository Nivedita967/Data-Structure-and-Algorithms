//C program for sum of 1d array
int* runningSum(int* nums, int numsSize, int* returnSize){
    int i;
    //create variable result
    int* result = (int*)malloc(numsSize*sizeof(int)); 
    result[i]=0;
    result[i] = result[i]+nums[i];
    for(i=1;i<numsSize;i++){
         //adding the previous elements
        result[i] = result[i-1]+nums[i];
    }
	*returnSize = numsSize;
    //return answer
    return result;
}

