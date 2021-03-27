
//C program to find top k frequent elements

//using hashtags
struct hashtable
{
    int value;
    int cnt;
};


//function cmp where subtraction is done
int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}
//function cmp where subtraction is done for hash variables
int cmph(const void *a, const void *b)
{
    return ((struct hashtable *)b)->cnt - ((struct hashtable *)a)->cnt;
}

int* topKFrequent(int* nums, int size, int k, int* returnSize) {
    //if size is zero or k is 0 then return 0
    if(k == 0 || size == 0){
        *returnSize = k;
        return 0;
    }
    //if size is less than k return 0
    if (size < k){
        *returnSize = 0;
        return 0;
    }
    //if size is equal to k or k is 1 then return nums
    if(size == k && k == 1){
        *returnSize = 1;
        return nums;    
    }
    //create a variable ans
    int *ans = calloc(k, sizeof(int));
    struct hashtable hash[size];
    memset(hash,0,sizeof(struct hashtable)*size);
    int i;
    int count=1;
    *returnSize = k;
    qsort(nums, size,sizeof(int),cmp);
    
    hash[0].value=nums[0];
    hash[0].cnt++;
    
    for (i=1;i<size;i++){
        //if hash value is same as nums then increament
        if(hash[count-1].value == nums[i]){
            hash[count-1].cnt++;
        } else {
            count++;
            hash[count-1].value = nums[i];
            hash[count-1].cnt++;
        }
    }
    
    qsort(hash, count,sizeof(hash[0]),cmph);
    //loop for storing answers in ans
    for(i=0;i<k;i++){
        ans[i] = hash[i].value;
    }
    //return answer
    return ans;
    
}

