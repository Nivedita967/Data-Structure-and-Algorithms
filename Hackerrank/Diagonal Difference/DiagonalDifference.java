import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'diagonalDifference' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts 2D_INTEGER_ARRAY arr as parameter.
     */

    public static int diagonalDifference(List<List<Integer>> arr) {
    
        int pd = 0,npd = 0;			//declaration and initialization
        for(int i=0;i<arr.size();i++)
        {
	    //to get the i-th element of the i-th list [on the principal diagonal(pd):top-left to bottom-right]
            pd+=arr.get(i).get(i);

	    //to get the (arr.size()-i-1)-th element of the i-th list [on the non-principal diagonal(npd) : top-right to bottom-left]
            npd+=arr.get(i).get(arr.size()-i-1);
        }
        return Math.abs(pd-npd);		//returns required difference	
    }

}

/*Driver Code : Provided by HackerRank*/
public class Solution 
{
    public static void main(String[] args) throws IOException 
{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<Integer>> arr = new ArrayList<>();

        IntStream.range(0, n).forEach(i -> {
            try {
                arr.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int result = Result.diagonalDifference(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
