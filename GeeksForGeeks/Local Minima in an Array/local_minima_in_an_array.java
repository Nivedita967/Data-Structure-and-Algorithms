public class LocalMinima {

 public int findLocalMinima(int [] arr, int start, int end){

 /*find the mid index*/
 int mid = start + (end-start)/2;
 int size = arr.length;

 /*check the local minima 
 *first check if left and right neighbor exists */
 if((mid==0 || arr[mid-1]>arr[mid]) &&
 (mid==size-1 || arr[mid+1]>arr[mid]))
 return arr[mid];
 
 /* check if left neighbor is less than mid element, if yes go left */
 else if(mid>0 && arr[mid]>arr[mid-1]){
 return findLocalMinima(arr, start, mid);
 }
 else { 
 /*check if right neighbor is greater than mid element, if yes go right */
 return findLocalMinima(arr, mid+1, end);
 }
 }
