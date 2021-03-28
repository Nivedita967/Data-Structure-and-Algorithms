import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'dynamicArray' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. 2D_INTEGER_ARRAY queries
     */

    public static List<Integer> dynamicArray(int n, List<List<Integer>> queries) {
    // Write your code here
Scanner z= new Scanner(System.in);
int lastAns=0,i,index,size,queryType,x,y;

List<Integer> seq =new ArrayList<Integer>();
List<List<Integer>> seqList = new ArrayList<List<Integer>>();

for(i=0;i<n;i++)
{
seq= new ArrayList<Integer>();
seqList.add(seq);
}
List<Integer> correct = new ArrayList<Integer>(); // create a list to store elements
for(List<Integer> q: queries)
{
queryType=q.get(0);
x=q.get(1);
y=q.get(2);
if(queryType==1)
{
index= (x^lastAns)%n;
seqList.get(index).add(y);
}
if(queryType==2)
{
index= (x^lastAns)%n;
size=seqList.get(index).size();
lastAns=seqList.get(index).get(y%size); //formula as per as problem
correct.add(lastAns);
}
}
return correct;
}

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int q = Integer.parseInt(firstMultipleInput[1]);

        List<List<Integer>> queries = new ArrayList<>();

        for (int i = 0; i < q; i++) {
            String[] queriesRowTempItems = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> queriesRowItems = new ArrayList<>();

            for (int j = 0; j < 3; j++) {
                int queriesItem = Integer.parseInt(queriesRowTempItems[j]);
                queriesRowItems.add(queriesItem);
            }

            queries.add(queriesRowItems);
        }

        List<Integer> result = Result.dynamicArray(n, queries);

        for (int i = 0; i < result.size(); i++) {
            bufferedWriter.write(String.valueOf(result.get(i)));

            if (i != result.size() - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
