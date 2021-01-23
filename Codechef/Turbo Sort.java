/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc= new Scanner(System.in);
		int n= sc.nextInt();
		int[] arr= new int[1000001];
		for(int i=0; i<n; i++){
		    arr[sc.nextInt()]++;
		}
		
		for(int i=0; i<1000001; i++){
		    while(arr[i]>0){
		       System.out.println(i);
		       --arr[i];
		    }
		    
		}
		
	}
}
