//TODO: Calculate factorial of given number
/* package codechef; // don't place package name! */

//TODO: Importing java packages
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
	public static int fact(int n) {      //TODO: Using recursion to find factorial
		if (n == 0 || n == 1) {      //TODO: Specifying base statement
			return 1;
		}
		return n * fact(n - 1);
	}

	public static void main(String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();
			System.out.println(fact(n));    //TODO: Printing result
		}
	}
}
