//TODO: Print balance after ATM transaction

import java.util.*;

class Codechef {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		//TODO: Getting user input
		int amount = sc.nextInt();
		double initial_balance = sc.nextDouble();
		
		//TODO: Checking and printing balance after transaction
		if (amount % 5 == 0 && initial_balance >= ((double) amount + 0.50)) {
			double balance = initial_balance - ((double) amount + 0.50);
			System.out.printf("%.2f", balance);
		} else {
			System.out.println(initial_balance);
		}
	}
}
