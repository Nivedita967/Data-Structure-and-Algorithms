bool isPalindrome(int x) {
    if(x<0)
        return false; // negative numbers cannot be a palindrome

    int num=x; 
    int a=0; //create a new variable for storing reversal of a number
    while(x)
    {
        a=a*10 + x%10; // find the reversal value of x
        x=x/10; 
    }
    if(a==num)
        return true; // if given number and its reversal is equal, return True
    else
        return false; // if given number and its reversal are not equal, return False
    
}
