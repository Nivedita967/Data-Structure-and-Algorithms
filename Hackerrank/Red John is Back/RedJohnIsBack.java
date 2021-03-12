import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
 
    public static final HashMap<Integer,String> factStore=new HashMap<Integer,String>();

      //to handle big integer while calculating prime numbers using Prime Sieve
    static BigInteger fact(int N)
    {
        if(factStore.containsKey(N))
            return new BigInteger(factStore.get(N));
     
        BigInteger f = new BigInteger("1");
        for (int i = 2; i <= N; i++)
            f = f.multiply(BigInteger.valueOf(i));
        
        factStore.put(N,String.valueOf(f));
        
        return f;
        
    }
    
    //function for Sieve
    public static int sieve(int n)
    {
        int count=0;
        boolean prime[] = new boolean[n+1];
        for(int i=0;i<=n;i++)
            prime[i] = true;
         
        //for optimisation run loop starting from p^2.
        for(int p = 2; p*p <=n; p++)
            if(prime[p] == true)
                for(int i = p*2; i <= n; i += p)
                    prime[i] = false;
         
        for(int i = 2; i <= n; i++)
            if(prime[i] == true)
                count++;

        return count;
    }
    
    //to count number of ways to tile the floor
    public static int countWays(int n)
    {
        int size=n;
        int sum=1;

        //using Hashmap we can count ho we can place 4 x 1 and 1 x 4 tiles 
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        map.put(1,size);
        map.put(4,0);
        while(map.get(1)>3)
        {
            map.put(1,map.get(1)-4);
            map.put(4,map.get(4)+1);
            if(map.get(1)!=0 && map.get(4)!=0)
            {
                BigInteger b1=fact(map.get(1));
                BigInteger b2=fact(map.get(4));
                BigInteger b=fact(map.get(1)+map.get(4));
                BigInteger res=b.divide(b1.multiply(b2));
                
                sum+=res.intValue();
            }

            else
                sum++;  
        }

        return sieve(sum);
    }

    //driver function for input and output
    public static void main(String[] args) {
      Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int l=0;l<t;l++)
        {
            int n=sc.nextInt();
            int res=countWays(n);
            System.out.println(res);
        }
    }
}
