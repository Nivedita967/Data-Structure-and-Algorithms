public static List<Integer> rotateLeft(int d, List<Integer> arr) {
    
    int n=arr.size(); //length of the array
    d=arr.size()-d; // to make the value in it's bound
    
    int s=0;int e=n-1;
    while(s<e)
    {
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
    return arr;

    }
