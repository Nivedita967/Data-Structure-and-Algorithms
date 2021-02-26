
import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the integer 'n': ");
        int num = sc.nextInt();
        System.out.println(countPrimes(num));
    }
    public static int countPrimes(int num) {
        int count = 0;
        boolean[] prime = new boolean[num+1];

        for (int i = 2; i <= num; i++) {
            prime[i] = true;
        }
        for (int p = 2; p*p <= num; p++){
            if(prime[p]){
                for (int j = p; j*p <= num; j++){
                    prime[j*p]=false;
                }
            }
        }
        for (int i = 2; i <= num; i++){
            if (prime[i]){
                count++;
            }
        }
        return count;
    }
}