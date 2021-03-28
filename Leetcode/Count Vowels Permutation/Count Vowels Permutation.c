// Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.
// Since the answer may be too large, return it modulo 10^9 + 7.

int countVowelPermutation(int n){

//returning 5 if n is equal to 1 
        if(n==1)
        {
            return 5;
        }

         //variable declaration
        long a=1,e=1,i=1,o=1,u=1,m=1000000007;

        //loop for finding vowel permutations 
        for(int i=1;i<n;i++)
        {
            long na=(e+i+u)%m, ne=(a+i)%m, ni=(e+o)%m, no=i, nu=(i+o)%m;
            a=na,e=ne,i=ni,o=no,u=nu;
        }

     //returning the count
        return (a+e+i+o+u)%m;
}
