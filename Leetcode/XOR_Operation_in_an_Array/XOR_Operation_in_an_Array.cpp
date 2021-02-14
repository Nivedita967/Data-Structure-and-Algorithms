int xorOperation(int n, int start) {
        int arr[n];// create the array wiht given number n
        int xorarray=0;
        
        for(int i=0;i<n;i++)
        {
            arr[i]=start+2*i; // according to the given condition 
            xorarray^=arr[i]; // applying Xor operation in the array to find the Xor of the array and store it into the variable named xorarray
        }
        return xorarray;// return the xorarray variable
    }
