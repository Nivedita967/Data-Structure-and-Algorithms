/*
The polar bears are going fishing. They plan to sail from (sx, sy) to (ex, ey). However, the boat can only sail by wind. 
At each second, the wind blows in one of these directions: east, south, west or north. Assume the boat is currently at (x, y).
If the wind blows to the east, the boat will move to (x + 1, y).
If the wind blows to the south, the boat will move to (x, y - 1).
If the wind blows to the west, the boat will move to (x - 1, y).
If the wind blows to the north, the boat will move to (x, y + 1).
Alternatively, they can hold the boat by the anchor. In this case, the boat stays at (x, y). Given the wind direction for t seconds,
 what is the earliest time they sail to (ex, ey)?

*/
import java.util.*;
public class Sail {
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
        // Taking input time in second t
		int t=sc.nextInt();
        // take in the starting & destination corordinates of Ship (x1,y1) to (x2,y2)
		int x1=sc.nextInt();
		int y1=sc.nextInt();
		int x2=sc.nextInt();
		int y2=sc.nextInt();
		String s=sc.next();
		char ch,ch1,ch2;
        // determing initial direction based on inital position & final position on ship.
		if(x2>x1)
			ch1='W';
		else
			ch1='E';
		if(y2>y1)
			ch2='S';
		else
			ch2='N';
		int i;
		for( i=0;i<t;i++)
		{
            // The starting location and the ending location will be different.
			ch=s.charAt(i);
			if(ch==ch1||ch==ch2)
				continue;
                // not on the x cordinate of destination
			if(x1!=x2)
			{
				if(ch=='E')
					x1++;
				if(ch=='W')
					x1--;
			}
            // not yet on the y coordinate of desctination
			if(y1!=y2)
			{
				if(ch=='N')
					y1++;
				if(ch=='S')
					y1--;
			}
            // Reached destination
			if(x1==x2&&y1==y2)
				break;			
		}
        // Not possible to sail under given wind condition
		if(i==t)
			System.out.print("-1");
        // the earliest time they sail to (x2, y2)
		else
			System.out.print(i+1);
	}
}