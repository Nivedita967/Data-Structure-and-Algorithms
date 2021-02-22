// * ALGORITHM =>
// * Fibonacci sequence is a sequence in which each number is the sum of previous two numbers.
// * For any fibonacci number F(n), the condition holds true => F(n) = ∑[F(n - 1) + F(n - 2)], for n >= 2.
// * Fibonaaci numbers starts from 0 and the next number is 1.
// * Eg => 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ....... ∞


// * Solution class =>
class Solution{
public:
    int fib(int n){
        int fib1 = 0, fib2 = 1, temp = 0;    // * First two numbers are 0 and 1 respectively and the rest of the numbers are the sum of previous 2 numbers.
        for (int i = 1; i <= n; i++){
            temp = fib2;
            fib2 = fib1 + fib2;
            fib1 = temp;
        }
        return fib1;
    }
};