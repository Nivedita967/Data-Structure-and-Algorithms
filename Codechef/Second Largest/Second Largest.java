//TODO: To find the second largest number from a given array of 3 numbers 
/* package codechef; // don't place package name! */

//TODO: Importing java packages
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
	public static void main(String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[3];                         //TODO: Getting user input
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < 3; j++) {
				arr[j] = sc.nextInt();         //TODO: Calculation of second largest integer
			}
			Arrays.sort(arr);
			System.out.println(arr[1]);            //TODO: Printing result
		}
	}
}
