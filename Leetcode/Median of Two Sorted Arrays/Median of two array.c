
// C Program to find median of two sorted Array
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    //num3Size length
int nums3Size = nums1Size+nums2Size;
    int *nums3 = (int *) malloc(sizeof(int)*nums3Size);
    int j=0, k=0;
    //if num3size is zero return zero
    if (nums3Size == 0) 
        return 0;
        //if nums1Size is zero
    else if (nums1Size == 0) {
        for (int i=0; i < nums2Size; i++) {
            nums3[i] = nums2[i];
        }
    }

    //if nums2Size is zero
    else if (nums2Size == 0) {
        for (int i=0; i < nums1Size; i++) {
            nums3[i] = nums1[i];
        }
    }
    ////if nums1Size, nums2Size and nums3Size are not zero
    else {
        for (int i=0; i < nums3Size; i++) {
            if (k == nums2Size && j < nums1Size){
                nums3[i] = nums1[j];
                j++;
            }
            else if (j == nums1Size && k < nums2Size) {
                nums3[i] = nums2[k];
                k++;
            }
            else if (nums2[k] < nums1[j]) {
                nums3[i] = nums2[k];
                k++;
            }
            else if (nums1[j] <= nums2[k]){
                nums3[i] = nums1[j];
                j++;
            }
        }
    }

    //if nums3Size is 1
    if (nums3Size == 1)
        return nums3[0];
        //checking if nums3Size is even and return answer
   else if (nums3Size % 2 == 0) {
       int index = nums3Size/2;
       double median = (nums3[index-1]+nums3[index])/(double) 2;
       return median;
   }
   //checking is nums3Size is odd and return answer
    else {
        printf("odd\n");
        return nums3[nums3Size/2];
    }
    return -1;
}

