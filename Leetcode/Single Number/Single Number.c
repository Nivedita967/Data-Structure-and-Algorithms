// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
int singleNumber(int* nums, int numsSize) {
    //initialize result to 0 to avoid garbage value
    int i, result = 0, size = numsSize;
    //iterate through array
    for (i = 0; i < size; i++) {
        //take xor of every number, xor of two same number results in 0 and hence the final result will be one occuring only once
        result ^= nums[i];

    }
	return result;
}