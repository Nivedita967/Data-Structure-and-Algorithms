//TODO: output the square root of the input integer, rounded down to the nearest integer

//TODO: Importing java packages
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
	public static void main(String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();   //TODO: Getting user inputs
		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();
			int res = (int) Math.sqrt(n);
			System.out.println(res);   //TODO: printing answer
		}
	}
}
