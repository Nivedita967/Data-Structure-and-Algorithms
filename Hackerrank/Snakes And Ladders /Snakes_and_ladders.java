import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

// *Complete the quickestWayUp function below.


// * ALGORITHM =>

// * The algorithm used here is Breadth First Search.
// * In this we first take into calculations how much do we have to travel for snakes as well as ladders and where will we land finally.
// * For this we keep a total of moves in distance array.
// * Then implementing the bfs using queue we update the moves array for each cell that depicts the number of minimum moves to reach that cell.
// * Atlast we normally return moves[n];

    static int quickestWayUp(int[][] ladders, int[][] snakes) {

        // * Distance array
        int distance[] = new int[101];

        for (int i = 0; i < ladders.length; i++) {
            distance[ladders[i][0]] += (ladders[i][1] - ladders[i][0]);
        }
        for (int i = 0; i < snakes.length; i++) {
            distance[snakes[i][0]] += (snakes[i][1] - snakes[i][0]);
        }

        // * Queue implemented for bfs algorithm
        Queue<Integer> que = new LinkedList<>();
        que.add(1);

        // * Moves default value is infinity
        int moves[] = new int[101];
        for (int i = 0; i < 101; i++) {
            moves[i] = Integer.MAX_VALUE;
        }


        boolean res = false;
        moves[1] = 0;
        for (int i = 2; i < 7; i++) {
            moves[i + distance[i]] = 1;
        }


        // * Loop until our queue is empty
        while (que.size() != 0) {
            int rn = que.poll();
            if (rn == 100) {
                res = true;
                break;
            }
            for (int i = 1; i <= 6; i++) {
                int x = rn + i;
                if (x <= 100 && x >= 1) {
                    x = x + distance[x];
                    if (x <= 100 && x >= 1) {
                        if (moves[x] >= moves[rn] + 1) {
                            moves[x] = moves[rn] + 1;
                            que.add(x);
                        }
                    }
                }

            }
        }
        if (!res) {
            return -1;
        }
        return moves[100];
    }


    // * Driver code =>
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[][] ladders = new int[n][2];

            for (int i = 0; i < n; i++) {
                String[] laddersRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < 2; j++) {
                    int laddersItem = Integer.parseInt(laddersRowItems[j]);
                    ladders[i][j] = laddersItem;
                }
            }

            int m = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[][] snakes = new int[m][2];

            for (int i = 0; i < m; i++) {
                String[] snakesRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < 2; j++) {
                    int snakesItem = Integer.parseInt(snakesRowItems[j]);
                    snakes[i][j] = snakesItem;
                }
            }

            int result = quickestWayUp(ladders, snakes);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}