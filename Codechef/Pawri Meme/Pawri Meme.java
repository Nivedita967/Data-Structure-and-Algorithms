// Lately, Chef has been inspired by the "pawri" meme. Therefore, he decided to take a string S and change each of its substrings that 
// spells "party" to "pawri". Find the resulting string.



import java.util.*;
import java.lang.*;
import java.io.*;

class Solution
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
        // Input: number of test cases
	    int T=sc.nextInt();
	    sc.nextLine();
	    while(T>0)
	    {
            // Input: take input String
		String str=sc.nextLine();
        // output the string by replacing all 'party' by 'pawri'
        System.out.print(str.replaceAll("party", "pawri"));
        System.out.print("\n");
        // decrement the test case 
        T--;
	    }
	}
}