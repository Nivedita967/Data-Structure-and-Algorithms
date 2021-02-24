import java.io.*;
import java.util.*;

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
        long max = Long.MIN_VALUE;
        long min = Long.MAX_VALUE;

        for(long a : A) {
            max = Math.max(max, a);
            min = Math.min(min, a);
        }

        return 2*(max-min);
    }
}