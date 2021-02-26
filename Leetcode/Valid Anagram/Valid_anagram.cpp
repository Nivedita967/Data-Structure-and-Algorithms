// * Problem Number - 242 (Valid Anagram)
// * Difficulty - Easy


// * ALGORITHM ==> 

// * ANAGRAM => Basically, a string is called an anagram of other string when both the string have the same types of characters with equal frequencies.
// * The approach below uses two maps, one for each string to store the frequency of each character occuring in the strings.
// * To solve it further, we just travel on either of the map and just compare the size of maps and frequency of each elements in both the strings.

// * The condition which needs to be checked and their importance are as follows -

// * 1) We check the size of maps. If they are equal then that means the "type" of characters occuring in both the string are the same. This will make sure that no extra or less characters are there when we draw a comparison among the strings.
// * 2) While travelling through the map we just check the "frequency" of a particular character in both the maps. If they are different then the strings can never be the anagrams of each other as the frequency of the characters is different.




// * Leetcode Solution Class
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> s_chars, t_chars; // * Initialising the maps

        for (int i = 0; i < s.size(); i++)   // * Storing & Counting frequencies of characters present in string 's'
        {
            s_chars[s[i]] += 1;
        }
        for (int i = 0; i < t.size(); i++)  // * Storing & Counting frequencies of characters present in string 't'
        {
            t_chars[t[i]] += 1;
        }

        for (auto character : t_chars)      // * Travelling the map of string 't', and checking for the frequencies and size of maps!
        {
            if (character.second != s_chars[character.first] || s_chars.size() != t_chars.size())
            {
                return false;
            }
        }
        return true;
    }
};



// * Example test cases given on Leetcode
/*
Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/