//CodeChef : Vaccine Distribution (VACCINE2)

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);    //for taking user-input
		int T = sc.nextInt();   		//the number of test cases
		for(int t = 1; t <= T; t++)
		{
		    int N = sc.nextInt();   		//total no. of people
		    int D = sc.nextInt();   		//max people that can be vaccinated per day
		    int a[] = new int[N];   		//array to store ages of N people
		    double r = 0.0;         		//declaration and initialization
		    for(int i = 0; i < N; i++)
		    {
		        a[i] = sc.nextInt();    	//scan age of i-th person
		        if(a[i] >= 80 || a[i] <= 9)     //check if the person is at risk
		        {
		            r++;
		        }
		    }
		    int daysRequired = (int) (Math.ceil(r/D) + Math.ceil((N-r)/D));
		    //Math.ceil() method rounds the specified double value upward and returns it

		    System.out.println(daysRequired);
		}
		
	}
}
