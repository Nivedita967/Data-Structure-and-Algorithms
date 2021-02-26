// Program for finding all possible substrings of a string using java

import java.util.Scanner;
 
public class AllSubStringsOfStringProgram
{
    private static void printAllSubstrings(String inputString)
    {   
        System.out.println("All possible substrings of "+inputString+" are : ");
        
         //Picking starting point
        for (int i = 0; i < inputString.length(); i++) 
        {

            //Picking ending point
            for (int j = i+1; j <= inputString.length(); j++) 
            {
                //printing substring from that start to endpoint
                System.out.println(inputString.substring(i, j));
            }
        }
    }
     
     //code for testing the above code
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
         
        System.out.println("Enter Input String : ");
         
        String inputString = sc.next();
         
        printAllSubstrings(inputString);
         
        sc.close();
    }
}