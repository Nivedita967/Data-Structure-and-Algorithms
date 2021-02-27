class solve{
    // Function to return maximum of sum without adjacent elements
    public int FindMaxSum(int arr[], int n){
        // Your code here

        //solved using constant space
        int maxsum=Integer.MIN_VALUE;

        int linc = 0; //last included
        int lexc = 0; //last excluded

        for(int i=0;i<n;i++){

            //calculating current maximum
            int currmax=Integer.MIN_VALUE;
            currmax = Math.max(linc, Math.max(lexc, lexc+arr[i]));

            //changing last included and excluded values for next call
            int temp = lexc;
            lexc = Math.max(linc, lexc);
            linc = temp + arr[i];

            //storing maximum value of sum 
            maxsum= Math.max(maxsum, currmax);
        }

        //returning maximum value
        return maxsum;
    }
}