//CodeChef: Highest Divisor (HDIVISR)

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);  //for taking user-input
		int N=sc.nextInt();		      //scan the number
		//here we iterate from 10 to 1 and print the 1st number (i.e. the largest) that divides n
		for(int i=10;i>0;i--)
		{
		    if(N%i==0)			      //checking if N is divisble by i
		    {
		        System.out.println(i);	      //print required highest divisor
		        break;			      //to exit the for-loop
		    }
		}
	}
}
