import java.util.Scanner;

public class DemoTranslation {
	/**
	 * Complete the following function.
	 */
	public static int marksSummation(int[] marks, int numberOfStudents, char gender) {
		int sum = 0;

        //check which gender
	    if(gender == 'b') {
			for(int i = 0; i < numberOfStudents; i += 2) { //boys, hence sum values at even places
				sum += marks[i];
			}
		} else {
			for(int i = 1; i < numberOfStudents; i += 2) { //girls, hence sum values at odd places/indices
				sum += marks[i];
			}
		}

		return sum;
	}

	public static void main(String[] args) {
		int numberOfStudents;
		char gender;
		int sum;


		numberOfStudents = STDIN_SCANNER.nextInt();
		int[] marks = new int[numberOfStudents];


        //take array input
		for(int student = 0; student < numberOfStudents; student++) {
			marks[student] = STDIN_SCANNER.nextInt();
		}

        //take gender input
		gender =  STDIN_SCANNER.next().charAt(0);
		sum = marksSummation(marks, numberOfStudents, gender);
		System.out.print(sum);
	}

	public final static Scanner STDIN_SCANNER = new Scanner(System.in);

	/**
	 * This method is missing from the Scanner interface.
	 */
	public final static int nextChar(Scanner scanner) {
		scanner.useDelimiter("");
		int ret = scanner.next().charAt(0);
		scanner.reset();
		return ret;
	}
}