/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc= new Scanner(System.in);
		int t= sc.nextInt();
		for(int i=0; i<t; i++){
		    int n= sc.nextInt();
		    int sum=0;
		    while(n>0){
		        sum+=n%10;
		        n=n/10;
		    }
		    System.out.println(sum);
		}
	}
}
