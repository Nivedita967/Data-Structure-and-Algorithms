/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Hxor
{
    public static boolean check(long n, int q) {
    long mask = (long)1 << q;
    
    if((n&mask)>0)
    return true;
    else
    return false;
   }

    public static int greatestBit(long n) {
      for (int i = 63; i >= 0; i--) {
        if( check(n, i) ) {
            return i;
        }
    }
    return -1;
   }
	public static void main (String[] args) throws IOException
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        long N,X;
        long arr[]=new long [100000];

        while(t-->0)
        {
             N=sc.nextInt();
             X=sc.nextInt();
             for(int i=0;i<N;i++)
             {
                 arr[i] = sc.nextLong();
             }
             long x =  0; int i = 0;
             while(x<X)
             {
                if (i == N-1) break;
                if (arr[(int) i] == 0) {
                    i++;
                    continue;
                }
                int p = greatestBit(arr[i]);
                int j = i + 1;
                while(j < N - 1) {
                    if ( check(arr[(int) j], p) ) {
                        break;
                    }
                    j++;
                }
                long twoRaisedToPowerP = ( (long)1 << p );
                arr[i] = arr[i]^twoRaisedToPowerP;
                arr[j] = arr[j]^twoRaisedToPowerP;
    
                x++;   
            }         
                long remainingOperations = X - x;
                if ( N == 2 && remainingOperations % 2 != 0 ) {
                    arr[(int)(N-2)] ^= 1;
                    arr[(int)(N-1)] ^= 1;
                }
              

                  OutputStream bout = new BufferedOutputStream(System.out); 
                for (long f = 0; f < N; f++) {
                    bout.write((arr[(int)f]+" ").getBytes()); 
                }
                bout.write(("\n").getBytes());

                bout.flush();
             
        }
	}
}

