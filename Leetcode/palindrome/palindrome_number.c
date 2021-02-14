#include <stdio.h>
int main() {
    int n, reversedN = 0, remainder, originalN;
    //Taking user input
    printf("Enter an integer: ");
    scanf("%d", &n);
    originalN = n;

    // reversed integer is stored in reversedN
    while (n != 0) {
        remainder = n % 10;                        //will give last digit
        reversedN = reversedN * 10 + remainder;     //forming reversed number
        n /= 10;
    }

    // palindrome if orignalN and reversedN are equal
    if (originalN == reversedN)
        printf("%d is a palindrome.", originalN);
    else
        printf("%d is not a palindrome.", originalN);

    return 0;
}
