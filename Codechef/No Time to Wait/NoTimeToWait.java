//CodeChef : No Time to Wait (NOTIME)

import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);		//to take user input
		boolean flag = false;				//declaration and initialization of flag variable
		int N = sc.nextInt();				//no. of different time zones
		int H = sc.nextInt();				//no. of hours needed to solve the problem
		int x = sc.nextInt();				//no. of hours left for the March Long Challenge
		int[] t = new int[N];				//array declaration
		for(int i=0;i<N;i++)
		{
		    t[i] = sc.nextInt();			//t[i] stores how many hours i-th time zone is behind current time
		    if( x + t[i] >= H)				//if problem can be solved by travelling to i-th time zone
		    {
		        flag = true;				//if problem has been solved, set flag variable to true
		        System.out.println("YES");
		        break;					//exit for loop
		    }
		}
		if(flag == false)				//if problem cannot be solved
		{
		    System.out.println("NO");
		}
	}
}
