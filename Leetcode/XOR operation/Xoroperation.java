class Xoroperation {
    public int xorOperation(int n, int start) {
        
        int[] ar = new int[n];
        for(int i = 0; i < n; i++) {
            ar[i] = start + 2*i;
        }

        int result = start;
        for(int i = 0; i < n-1; i++) {
            result = result ^ ar[i+1];
        }
        return result;  
    }
}