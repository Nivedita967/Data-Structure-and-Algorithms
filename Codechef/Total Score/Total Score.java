// There are K problems in a contest with N participants. All the problems don't necessarily have the same points assigned to them - 

// you are given an array A of integers, where Ai denotes the points assigned to the ith problem. If a participant solves the ith
//  problem, they will get Ai points added to their total score. Note that there are no partial points - they can get only 0 or Ai points on 
//  the ith problem. For each participant i, you are also given their final verdict in each problem in the form of a binary string Si - a 1 
//  denotes that they solved that problem, and a 0 denotes that they did not.

import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        // initialize input stream
        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static void main(String args[]) {
        FastReader sc=new FastReader();
        int t = sc.nextInt();
        while (t-- > 0) {
            // n= the number of participants
            // k= the number of problems in the contest respectively.
            int n = sc.nextInt();
            int k= sc.nextInt();
            long arr[]= new long[k];
            // traverse till k
            for(int i=0;i<k;i++)
            {
                arr[i]= sc.nextLong();
                }
            String []s = new String[n];
            // allocate value to s[i]
            for(int i=0;i<n;i++)
            {
                s[i] =sc.next();

            }
            for(int i=0;i<n;i++)
            {
                long output=0;
                for(int j=0;j<k;j++)
                {
                   // int a=
                    if(s[i].charAt(j)=='1')
                  output += arr[j];
                }
                // print the output
                System.out.println(output);

            }
        }
    }
}