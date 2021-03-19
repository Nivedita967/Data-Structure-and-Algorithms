import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    // Complete the prims function below.
    static int prims(int n, int[][] edges, int start) {
      boolean[] mst = new boolean[n];
    Arrays.sort(edges, new Comparator<int[]>(){   //sort the array using java comprator
        public int compare(int[] a, int[] b){
            return a[2]-b[2];
        }
    });
    int m = edges.length;
    int ans = edges[0][2];
    mst[edges[0][0]-1]=true;mst[edges[0][1]-1]=true;
    while(n-2>0){
        for(int i=1;i<m;i++){
            if((mst[edges[i][0]-1] ^ mst[edges[i][1]-1])==true){
                ans+=edges[i][2];         // calculate the result 
                mst[edges[i][0]-1]=true;
                mst[edges[i][1]-1]=true;
                n--;
                break;
            }            
        }
    }
    return ans;                            //print the result
    }
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        int[][] edges = new int[m][3];

        for (int i = 0; i < m; i++) {
            String[] edgesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int edgesItem = Integer.parseInt(edgesRowItems[j]);
                edges[i][j] = edgesItem;
            }
        }

        int start = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int result = prims(n, edges, start);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
