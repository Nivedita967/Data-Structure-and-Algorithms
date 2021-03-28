import java.util.*;

class Solution
{
	public static void main(String[] args)
	{
		try {

			Scanner sc=new Scanner(System.in);
            // t = number of test cases
			int t=sc.nextInt();
			while(t!=0) {
                // input integer c
				int c=sc.nextInt();
				int temp=c,count=0;
                // finding d
				while(temp>0) {
					temp=temp/2;
					count++;
				}
				int a=(int) (Math.pow(2, count-1)-1);
                // bit vise operation of a & c
				int b=a^c;
                // printing a.b
				System.out.println(a*b);
			}
		}
		catch(Exception e) {
			return;
		}
	}		
}
