// C program to sort an array with 0, 1 and 2
// in a single pass
#include <stdio.h>
/* Function to swap *a and *b */
void swap(int* a, int* b);
// Sort the input array, the array is assumed to
// have values in {0, 1, 2}
void sort(int *a, int arr_size)
{
    int k = 0;
    int b = arr_size - 1;
    int c = 0;
    while (c <= b) {
        switch (a[c]) {
        case 0:
            swap(&a[k++], &a[c++]);
            break;
        case 1:
            c++;
            break;
        case 2:
            swap(&a[c],&a[b--]);
            break;
        }
    }
}
/* UTILITY FUNCTIONS */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size)
{
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
}
/*main function*/
int main()
{
    int arr[100],a;
    scanf("%d",&a); /* taking size as input from the user*/
    for(int z=0;z<a;z++)
    {
    scanf("%d",&arr[z]);
    }
    sort(arr, a);
    printArray(arr,a);
    return 0;
}