public static List<Integer> rotateLeft(int d, List<Integer> arr) {
    // Write your code here
    int n=arr.size();// store the size of array in variable n
    d=arr.size()-d; // subtract the value of d from size of array to make right rotation of it
    //now we will apply 3 loops where rotation of 0 to n-1 , 0 to d-1 and d to n-1 will take place
    int s=0;int e=n-1;
    while(s<e)
    { // swap the value untill start is less than end to rotate the array
        Integer temp=arr.get(s);
        arr.set(s,arr.get(e));
        arr.set(e,temp);
        
        s++;e--;
    }
    
    s=0;e=d-1;
    while(s<e){
    
        Integer temp=arr.get(s);
        arr.set(s,arr.get(e));
        arr.set(e,temp);
        
        s++;e--;
    }
    
    s=d;e=n-1;
    while(s<e)
    {
      Integer temp=arr.get(s);
        arr.set(s,arr.get(e));
        arr.set(e,temp);
        
        s++;e--;
    }
    return arr; // return the required modified array

    }
