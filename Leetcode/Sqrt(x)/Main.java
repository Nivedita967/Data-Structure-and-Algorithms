class Solution {
    public int mySqrt(int x) {
    long r = x;
 //      approach: Newton's method for root-finding
//       ref: https://en.wikipedia.org/wiki/Newton%27s_method

        while(r*r>x)
            r = (r+x/r)/2;
        
        return (int) r;
            
        
    }
}
