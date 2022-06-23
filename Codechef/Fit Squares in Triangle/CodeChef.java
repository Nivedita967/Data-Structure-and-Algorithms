import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class CodeChef
{
	public static void main (String[] args)
	{
		// your code goes here
		Scanner n=new Scanner(System.in);
		int t=n.nextInt();
		for(int i=0;i<t;i++){
		    int base,squares=0;
		    base=n.nextInt();
		    while(base > 2 )
	        {
	            squares+=(base-2)/2;
	            base = base-2;
	        }
		    System.out.println(squares);
		}
	}
}