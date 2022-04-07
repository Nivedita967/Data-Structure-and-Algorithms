import java.util.Scanner;

class main{
    public static void main(String[] args)
    {
        // Taking User input as string
        Scanner scan = new Scanner(System.in);
        String s = scan.next();

        // Adding value integer value of all characters to sum
        int sum = 0;
        for (int i = 0; i < 5; i++) 
        {
            char c = s.charAt(i);
            sum += (c-48);  
            // Finding numirical value of the character by taking help of its corresponding ASCII value
        }
        System.out.println(sum);
    }
}
