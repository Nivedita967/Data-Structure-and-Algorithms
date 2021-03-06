class Solution
{
    public int fun(String str)
    {
        // Write your code here
        int N=1000000007; //for modulo
        int a=0, ab=0, abc=0;  // strings ending with a, ab, and abc

        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='a'){
                a = ((2*(a%N))%N +1)%N;  //count of strings ending with a 
            }
            else if(str.charAt(i)=='b'){
                ab = ((2*(ab%N))%N + a)%N;   //count of strings ending with ab
            }
            else{
                abc = ((2*(abc%N))%N + ab)%N;    //count of strings ending with abc
            }
        }
        return abc%N;  //returning count of final strings
    }
}