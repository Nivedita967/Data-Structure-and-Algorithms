// You are given an integer n. Check if n has an odd divisor, greater than one (does there exist such a number x (x>1) 
// that n is divisible by x and x is odd).

// For example, if n=6, then there is x=3. If n=4, then such a number does not exist.
import java.util.*;
public class OddDivisor {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a,b;
        // a =  test case
		a=sc.nextLong();
		while(a-->0) {
            // input number
			b=sc.nextLong();
           
            // Eliminating the even divisors
			while(b%2==0) {
				b=b/2;
			}
            // checking if b has odd divisors
			if(b==1) {
				System.out.println("NO");
			}
            // YEs: has odd divisors
			else {
				System.out.println("YES");
			}
		}
		
		sc.close();
	}

}