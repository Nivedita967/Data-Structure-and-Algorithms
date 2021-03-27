
// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3


// Example 2:
// Input: s = "bbbbb"
// Output: 1



public int lengthOfLongestSubstring(String s) {
    // If the length of string is 0 then return 0 as length of substring for that string will also be 0
    if("".equals(s)){ 
        return 0;
    }

    // Initialize a new ArrayList
    List<Character> strings = new ArrayList<Character>();
    int longest , count  = 0;

    for(int i = 0; i < s.length() ; i++){
        Character v = s.charAt(i);
        // when repeat is found, reset back to the last occurrence prior to current.
        if(strings.contains(v)){  
            int index = s.substring(0 , i).lastIndexOf(v);
            i = index;
            count  = 0;
            strings.clear();
            continue;
        }
        // add that non repeating character to the arraylist
        strings.add(v);
        // Increment count
        count++;
        if(count > longest){
            longest = count;
        }
    }
    // return the longest substring without repeating characters
    return longest;
}