//TODO: A Program in java to find out minimum no. of notes to be given for an amount

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc= new Scanner(System.in);    
        int t= sc.nextInt();
    for(int i = 0; i < t;i++)                   //TODO: Take user input
    {
        int n= sc.nextInt();
        int count = 0;
        while (n >= 100)                        //TODO: Calculating 100 rupees note
        {
            n -= 100;
            count++;
        }
        while (n >= 50)                         //TODO: Calculate 50 rupees note
        {
            n -= 50;
            count++;
        }
        while (n >= 10)                        //TODO: Calculate 10 rupees note
        {
            n -= 10;
            count++;
        }while (n >= 5)                        //TODO: Calculate 5 rupees note
        {
            n -= 5;
            count++;
        }
        while (n >= 2)                          //TODO: Calculate 2 rupees note
        {
            n -= 2;
            count++;
        }
        while (n >= 1)                           //TODO: Calculate 1 rupee note
        {
            n -= 1;
            count++;
        }
        System.out.println("" +count);                       //TODO: Printing result
    }
	}
}

