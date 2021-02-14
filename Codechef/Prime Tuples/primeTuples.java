import java.util.*;
import java.lang.*;
import java.io.*;

class primeTuples
{
    
    static void sieve(int n, boolean prime[]) //Finding prime numbers using Sieve of Eratosthenes
    { 
        for (int p = 2; p * p <= n; p++) { 
      
            if (prime[p] == true) { 
                // Update all multiples of p 
                for (int i = p * p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
    } 
    
    static void primeTuples(int n) 
    { 
        // Finding all primes from 1 to n 
        boolean prime[]=new boolean[n + 1]; 
        Arrays.fill(prime,true); //initialise the entries as true
        sieve(n, prime); 
        
        int count = 0;
          
        for (int i = 3; i <= n-2; ++i) { 
            if (prime[2] && prime[i] && prime[i + 2])  // Compute the prime tuple values
                count++; 
        } 
        System.out.println(count); // Print result
    } 
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine()); // take in the number of entries
		
		for(int i=0; i<n; ++i){
		    int a = Integer.parseInt(br.readLine()); // take in the values
		    primeTuples(a);
		}
	}
}
