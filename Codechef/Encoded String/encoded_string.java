/* Program to decode the string where each character belongs from first 16 alphabet. Each alphabet encoded in 4 bit string 
of 0 or 1 */

import java.util.*;
import java.lang.*;
import java.io.*;
class Codechef
{
 public static void main (String[] args) throws Exception
 {
  BufferedReader br=new BufferedReader(new InputStreamReader(System.in)); /* Here we declare a variable which can read the argument */
  int n=Integer.parseInt(br.readLine());          /* Here we take first value from user, which is saying how many string you want to decode */
  while(n--!=0){
      int size=Integer.parseInt(br.readLine());   /* Here we take the size of encoded string */
      String str=br.readLine();                   /* we read the encoded string in the form of o or 1. User has to enter atleast 4 bit for each character like 1001-for 1 character, 00001111-for 2 character..etc */ 
      String s="";
      String ans="";
      for(int i=0;i<size;i=i+4){                 /* This loop have task to read the input string in a bunch of 4 bit and make substring of 4-4 bit */
          if((i+4)==size)
              s=str.substring(i);
          else
              s=str.substring(i,i+4);
              
         int start=0;
         int mid=0;
         
        String arr="abcdefghijklmnop";           /* A string of first 16 alphabet */
        int end=arr.length();
        String a="";
        for(int j=0;j<s.length();j++){          /* this loop has task to read the entire string which user has provided, stored in s */
            
            if(s.charAt(j)=='0'){               /* this condition says if bit is 0 then character must lie in first half of arr */ 
                mid=(start+end)/2;
                a=arr.substring(start,mid);
                end=mid;
            }
            else{                               /* for this if bit is 1 then character must lie in second half of the arr */
                mid=(start+end)/2;
                if(end==16)
                    a=arr.substring(mid);
                else
                    a=arr.substring(mid,end);
                start=mid;
            }
        }                                       /* after reading each bit we can find out the exact character for each 4 bit combination like 1001 represents j */
        ans=ans+a;
      }
      System.out.println(ans);                  /* Print the character from the encoded string */
  }
 }
}