import java.util.*;
import java.lang.*;
import java.io.*;
// We have to count the number of cars which were moving at their maximum speed on the straight segment.
class Solution
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		
		StringBuilder sb=new StringBuilder();
        // t = testcases
		while(t-->0)
		{
		    int n=sc.nextInt(); //taking the number of cars
		    int k=sc.nextInt();
		    int m[]=new int [k];
		    for(int i=0;i<k;i++)
		    {
		        m[i]=sc.nextInt();
		    }
		    sc.nextLine();
            // Calculating the number of cars at their maximum speed
		    for(int i=0;i<n;i++)
		    {
		        long sum=0;
		        String st1=sc.next();
		        for(int j=0;j<k;j++)
		        {
		            int a=Integer.parseInt(st1.substring(j,j+1));
		            if(a==1)
		            {
		                sum=sum+m[j];
		            }
		        }
		        sb.append(sum+"\n");
		    }
		    
		}
        // Printing the result
		 System.out.print(sb);
	}
}