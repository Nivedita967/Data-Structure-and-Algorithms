def minion_game(string):
    # your code goes here
    # storing all the vowels
    vowels_string = 'aeiouAEIOU'
    
    # For calculating scores
    vowels = consonants = 0

    n = len(string)

    # enumerate will help to store the index and it's value
    # For more explanation see at last
    for i,l in enumerate(string):
        if l in vowels_string:
            vowels += (n-i)
        else:
            consonants += (n-i)
    
    if vowels == consonants:
        print('Draw')
    elif vowels>consonants:
        print('Kevin {}'.format(vowels))
    else:
        print('Stuart {}'.format(consonants))

# Internal HackerRank code (already given)
if __name__ == '__main__':
    s = input()
    minion_game(s)

"""
0 1 2 3 4 5
B A N A N A

Each letter will have n - i substr
Like for B (0) will have (6 - 0 = 6) substr
B
BA
BAN
BANA
BANAN
BANANA

Similarly for others. So each time we will check that if it is vowel or not.

At last we will check that if number of vowel is greater then Kevin wins, is same then Draw else Stuart wins.
"""