import java.util.*;
/* Name of the class has to be "Main" only if the class is public. */
class CodeChef
{
	public static void main (String[] args)
	{
		// your code goes here
		Scanner n=new Scanner(System.in);
		int t=n.nextInt();
		for(int i=0;i<t;i++){
			/* Let consider the right angle isosceles triangle ABC with base 12. It has many layers of squares, each layer that may contain many squares,is'nt it*/
		    int base,squares=0;
		    base=n.nextInt();
		    while(base > 2 )//check for base whether is it less than two. when base is not two then no more square can be added to triangle.
	        {
	            squares+=(base-2)/2;/*
				* We are reducing the base by 2 and divide by 2
	            * In single layer of a triangle,
	            * We minus 2, make sure we remove the part where we can't fit the square due to the slope in triangle
	            * Then we divide by two which caculate the number of square that can fit in that layer*/
	            base = base-2;/*  Now we reduce the base by two, moving to above layer (like from bottom to top)
	            * And the loop continue till it reach the base equal to 2 where we can no more fit the square
	            */

	        }
		    System.out.println(squares); // At last we print the value of the square
		}
		n.close();
	}
}