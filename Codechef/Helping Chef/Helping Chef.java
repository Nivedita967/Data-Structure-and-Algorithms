//TODO: Printing strings for specific inputs
/* package codechef; // don't place package name! */

//TODO: Importing java packages
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
	public static void main(String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);   //TODO: getting user input
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();
			if (n < 10) {
				System.out.println("Thanks for helping Chef!");   //TODO: Printing strings
			} else {
				System.out.println(-1);
			}
		}
	}
}
