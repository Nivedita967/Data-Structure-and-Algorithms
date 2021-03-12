import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

//	Taking input from user in java Scanner class is imported from util java library
		Scanner scan = new Scanner(System.in);
//	Declare four variables here two variables of integer type and two of float type
		int a, b;
		float c, d;
//    way to take integer input
		a = scan.nextInt();
		b = scan.nextInt();
//    way to take float input
		c = scan.nextFloat();
		d = scan.nextFloat();
//    for printing the output on console, println is used.
		System.out.println((a + b) + " " + (a - b));
		System.out.println((c + d) + " " + (c - d));
	}

}
