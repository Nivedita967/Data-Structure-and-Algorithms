/*
Vasya decided to write an anonymous letter cutting the letters out of a newspaper heading. He knows heading s1 and text s2 that he wants to send. 
Vasya can use every single heading letter no more than once. Vasya doesn't have to cut the spaces out of the heading — he just leaves some blank
 space to mark them. Help him; find out if he will manage to compose the needed text.
*/
import java.util.*;
class Solution {
    public String checkLetter(String s1, String s2){
        Boolean flag = true;
        Map<Character, Integer> mapOccurances = new HashMap<>();

        // creating hashmap for characters for s1 as key and their occurances as values.
        for(int i = 0 ; i < s1.length() ; i++){
            // mapOccurances.getOrDefault(s1.charAt(i), 0) + 1 : if s1.charAt(i) already exits in the map then it will give its value otherwise it would give 0 by default
           mapOccurances.put(s1.charAt(i),mapOccurances.getOrDefault(s1.charAt(i), 0) + 1) ;
        }

        //loop for checking if Vasya can write the given anonymous letter
        for(int i = 0 ; i < s2.length() ; i++){
            if(mapOccurances.get(s2.charAt(i)) > 0 || s2.charAt(i) == ' '){
                // reduce the number of occurance from map since its one occurance has been counted.
                mapOccurances.put(s2.charAt(i),mapOccurances.get(s2.charAt(i)) - 1);
                continue;
            }
            else{
                flag = false;
                break;
            }
        }

        if(flag){
            return "YES";
        }
        else{
            return "NO";
        }
    }

}
