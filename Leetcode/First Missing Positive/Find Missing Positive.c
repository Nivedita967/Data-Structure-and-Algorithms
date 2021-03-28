int firstMissingPositive(int* nums, int numsSize){
    bool isChanged; //flag to keep a track of numbers present
    int min = 1; //initialize variables
    
    do {
        isChanged = false;
        
        for (int i = 0; i < numsSize; i++) { //iterate through the array
            if (nums[i] == min) { 
                min++;
                isChanged = true;
            }
        }
    } while (isChanged); //once false, we have found the number
        
    return min;
}