// # A program in java to find out the number of different digits used in it.
class Solution{
    public static void digitFrequency(String str){
        //  Creating an array to count number of all 10 digits (0 to 9)
        int[] arr = new int[10];  
        // # Iterating through every element of string and updating the array
        for(int i = 0 ; i < str.length(); i++){
            char c = str.charAt(i);
            int ascii = c; 
            if(ascii > 47 && ascii < 58){
                arr[ascii-48] += 1;
            }
        }
        // # Printing the array containing number of occurances
        for(int i = 0 ; i < arr.length ; i++){
            System.out.print(arr[i]+" ");
        }

    }
}