import java.io.*;
import java.util.*;

/*
* Problem Name: Maximise Function
* Problem URL: https://www.codechef.com/FEB21B/problems/MAXFUN
* Logic: If the array is sorted in ascending order, and we choose the three numbers x,y,z such that x < y < z and Ax <= Ay <= Az
* then |Ax - Ay| + |Ay - Az| + |Az - Ax| = (Ay - Ax) + (Az - Ay) + (Az - Ax) = 2*(Az - Ax).
* Hence the objective is to maximize (Az - Ax) such that x < z and Ax <= Az. Hence the solution is the difference between maximum
* and minimum of the array.
*
* Time Complexity - O(n)
* Space Complexity - O(n)
*/

public class MaximiseFunction
{
    public static void main(String[] args)
    {
        MaximiseFunction solver = new MaximiseFunction();
        Scanner sc = new Scanner(System.in);
        StringBuilder answer = new StringBuilder();
        
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = sc.nextInt();
            long[] A = new long[N];

            for(int i = 0;i < N;i++)
                A[i] = sc.nextInt();

            answer.append(solver.solve(N, A)).append('\n');
        }
        System.out.print(answer);
    }

    public long solve(int N, long[] A) {
        long max = Long.MIN_VALUE; // Setting the initial max value as lowest long value
        long min = Long.MAX_VALUE; // Setting the initial min value as largest long value

        for(long a : A) {
            // Updating max and min using Math Library
            max = Math.max(max, a);
            min = Math.min(min, a);
        }

        return 2*(max-min); // Returning the answer.
    }
}