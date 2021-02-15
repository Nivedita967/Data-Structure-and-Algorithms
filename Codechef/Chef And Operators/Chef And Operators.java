//TODO: Compare two numbers given by user and print '<' , '>' , '=' appropriately

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
	public static void main(String[] args) throws java.lang.Exception {
		//TODO: getting number of test cases
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		//TODO: Getting numbers for comparision and printing results
		for (int i = 0; i < t; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if (a > b) {
				System.out.println(">");
			} else if (a < b) {
				System.out.println("<");
			} else {
				System.out.println("=");
			}
		}
	}
}
