// Link to the problem : https://www.codechef.com/problems/PTUPLES

import java.util.*;
import java.io.*;

public class Main{
    public static int n = 1000001;
    public static boolean prime[]=new boolean[n+1]; 
    public static int answer[]=new int[n];
    
    static void sieve() //Finding prime numbers using Sieve of Eratosthenes
    { 
        Arrays.fill(prime,true);  //initialise the entries as true
        Arrays.fill(answer,0);    //initialise the entries as 0
        
        prime[0]=false;
        prime[1]=false;
        
        for (int p = 2; p * p <= n; p++) { 
            if (prime[p] == true) { 
                // Update all multiples of p 
                for (int i = p * p; i <= n; i += p) 
                    prime[i] = false; // compute the prime numbers
            } 
        }
        
        
        int count = 0;
        for (int i = 5; i < n; ++i) { 
            if (prime[i] && prime[i - 2]){ //determine prime tuples
                count++; 
            }
            answer[i] = count;  
        } 
    
    } 
    
    public static void main (String[] args) throws java.lang.Exception{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter pw = new PrintWriter(System.out);
	try{
		int a;
		sieve();
		int n = Integer.parseInt(br.readLine()); //number of entries
		for(int i=0; i<n; i++){
			a = Integer.parseInt(br.readLine());
			if(a < 5){
			    System.out.println("0");
			    continue;
			}
			pw.println(answer[a]); //print the number of possible prime tuples
		}
		pw.flush();
		pw.close();
	}
        catch(Exception ex){

        }
    }
}
