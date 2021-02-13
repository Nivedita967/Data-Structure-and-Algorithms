//TODO: Print number of occurences of the digit 4 in the respective integer from Kostya's list.
/* package codechef; // don't place package name! */

//TODO: Importing java packages
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
	public static void main(String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);   //TODO: Taking user input
		int t = sc.nextInt();
		for (int i = 0; i < t; ++i) {
			int n = sc.nextInt();
			int count = 0;
			
			//TODO: Calculating answer
			while (n > 0) {
				if (n % 10 == 4) {
					++count;
				}
				n = n / 10;
			}
			System.out.println(count);   //TODO: Printing answer
		}
	}
}
