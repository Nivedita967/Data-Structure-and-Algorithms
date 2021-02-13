

public class Solution {
    // Complete  hourglassSum function below.
    static int hourglassSum(int[][] arr) {
        int max=-63;
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        int current_sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j+1]
        +arr[i+2][j]+arr[i+2][j+2];
        //comparing sum with maximum value
        if(current_sum>max)
{
    max=current_sum;
}
    }
}
return (max);
    }