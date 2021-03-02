//CodeChef : Chef and Coupon (COUPON2)

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);						//to take user input
		int t = sc.nextInt();								//no. of test cases
		while(t-- > 0)									//loop for test cases
		{
		    int D = sc.nextInt();							//delivery charges
		    int C = sc.nextInt();							//coupon's cost

		    //costs of food items ordered on Day 1
		    int a1 = sc.nextInt();
		    int a2 = sc.nextInt();
		    int a3 = sc.nextInt();

		    //costs of food items ordered on Day 2
		    int b1 = sc.nextInt();
		    int b2 = sc.nextInt();
		    int b3 = sc.nextInt();

		    int sumA = a1 + a2 + a3;							//total cost of food items ordered on Day 1
		    int sumB = b1 + b2 + b3;							//total cost of food items ordered on Day 2
		    int sum = sumA + sumB;							//total cost of food items ordered on Day 1 & 2

		    if(sumA >= 150 && sumB >= 150 && ((sum + C) < (sum + D + D)))		
		    {
			//if coupon is applicable on both days and total cost after using coupon is less than total cost without coupon
		        System.out.println("YES");
		    }
		    else if(sumA >= 150 && sumB < 150 && ((sum + C + D) < (sum + D + D)))
		    {
			//if coupon is applicable on Day 1 only and total cost after using coupon is less than total cost without coupon
		        System.out.println("YES");
		    }
		    else if(sumA < 150 && sumB >= 150 && ((sum + C + D) < (sum + D + D)))
		    {
			//if coupon is applicable on Day 2 only and total cost after using coupon is less than total cost without coupon
		        System.out.println("YES");
		    }
    		    else
    		    	System.out.println("NO");						//Chef should not buy the coupon in this case
		}
	}
}
