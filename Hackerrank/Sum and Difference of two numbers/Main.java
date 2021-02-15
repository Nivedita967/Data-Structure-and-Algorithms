import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
	Scanner scan = new Scanner(System.in);
	int a,b;
    float c,d;
    a = scan.nextInt();
    b = scan.nextInt();
    c= scan.nextFloat();
    d=scan.nextFloat();
    
    System.out.println((a+b)+" "+(a-b));
    System.out.println((c+d)+" "+(c-d));
	}

}
