def minion_game(string):
    # your code goes here
    vowels_string = 'aeiouAEIOU'
    vowels = consonants = 0

    n = len(string)
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
if __name__ == '__main__':
    s = input()
    minion_game(s)