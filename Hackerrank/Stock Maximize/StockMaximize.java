import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'stockmax' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts INTEGER_ARRAY prices as parameter.
     */

    public static long stockmax(List<Integer> prices) {
    // Write your code here

        long max_=0;
        // using the concept of next greater price while travelling in reverse order on the array
        Stack<Integer> stk = new Stack<Integer>();
        int lastmax= prices.get(prices.size()-1);
        stk.push(prices.get(prices.size()-1));

        // travelling on prices array in reverse order 
        for(int i=prices.size()-2; i>=0; i--){

            // base conditions 
            if(stk.size()==0 || stk.peek() >= prices.get(i) || prices.get(i) <= lastmax){
                stk.push(prices.get(i));
            }

            // always push the current price in stack 
            else{
                while(stk.size()!=0){
                    max_+= (lastmax-stk.peek());
                    stk.pop(); 
                }
                lastmax = prices.get(i);
                stk.push(prices.get(i));
            }
        }

        // empty the stack at last and update maximum
        while(stk.size()!=0){
            max_+= (lastmax-stk.peek());
            stk.pop(); 
        }

        // returning Maximum
        return max_;
    }
}

//driver Code
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        for (int tItr = 0; tItr < t; tItr++) {
            int n = Integer.parseInt(bufferedReader.readLine().trim());

            String[] pricesTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> prices = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                int pricesItem = Integer.parseInt(pricesTemp[i]);
                prices.add(pricesItem);
            }

            long result = Result.stockmax(prices);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedReader.close();
        bufferedWriter.close();
    }
}
