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
		int n = scan.nextInt();
		
		for(int i=0 ;i<n; i++){
		    int a[] = new int[n];
		    for(int j=0; j<10; j++)
		        a[j] = scan.nextInt();
		    int k = scan.nextInt();
		    
		    int j=9;
		    while(k >= a[j]){
		        k = k - a[j];
		        j--;
		    }
		    System.out.println(j+1);
		}
	}
}
