/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
	    	Scanner scan = new Scanner(System.in); 
		int n = scan.nextInt(); //input the number of test cases

		for(int i=0 ;i<n; i++){
		    int a[] = new int[n]; // array initialisation
		    for(int j=0; j<10; j++)
			a[j] = scan.nextInt(); //array of integers
			
		    int k = scan.nextInt(); //the number of problems to be deleted

		    int j=9;
		    while(k >= a[j]){
			k = k - a[j];
			j--; //obtain the minimum difficulty of the most difficult remaining problem.
		    }
		    System.out.println(j+1); //Print the result
		}
	}
}
