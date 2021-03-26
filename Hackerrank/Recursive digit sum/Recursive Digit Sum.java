// We define super digit of an integer x  using the following rules:
// Given an integer, we need to find the super digit of the integer.
// -> If x  has only  digit, then its super digit is x.
// -> Otherwise, the super digit of x is equal to the super digit of the sum of the digits of x
import java.util.*;


public int SuperDigit(String n, int k) {
    int sum = 0;
    // Traversing through each charcter of string & adding it to sum to find superdigit
    for(int i = 0; i < n.length(); i++ ) {
        sum += (n.charAt(i) - '0');
        if(sum > 9) {
            sum -= 9;
        }
    }
    // Since the same string would be repeated k times.
    sum = sum * k;
    sum = sum % 9;
    // sum == 0 return 9
    if(sum == 0) {
        return 9;
    }
    return sum;

}


