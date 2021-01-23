/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc= new Scanner(System.in);
		int t= sc.nextInt();
		int max_lead= 0;
		int max_lead_player=0;
		int c1=0, c2=0;
		for(int i=0; i<t; i++){
		    int p1= sc.nextInt();
		    int p2= sc.nextInt();
		    c1+= p1;
		    c2+= p2;
		    int lead= Math.abs(c1-c2);
		    if(lead>max_lead){
		        max_lead= lead;
		        if(c1>c2){
		            max_lead_player= 1;
		        }else{
		            max_lead_player= 2;
		        }
		    }
		}
		System.out.println(max_lead_player+ " "+ max_lead);
	}
}
