//TODO: display the sum of first and last digits of N in a new line.
/* package codechef; // don't place package name! */

//TODO: Importing java packages
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
	public static void main(String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();   //TODO: Getting user input 
			int digits = (int) Math.log10(n);
			int first = (int) (n / Math.pow(10, digits));   //TODO: calculating answer
			int last = n % 10;
			System.out.println(first + last);   //TODO: printing answer
		}
	}
}
