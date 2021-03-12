# A program in python to find out the number of different digits used in it.


string = input("Enter string: ")                   # Getting user input

ocurance = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]          # Creating an array to count number of all 10 digits (0 to 9)

for c in string:                                   # Iterating through every element of string and updating the array
    o = ord(c)
    if o > 47 and o < 58:
        ocurance[o-48] += 1

for i in ocurance:                                 # Printing the array (list) containing number of occurances
    print(i, end=" ")
print()                                            # Printing a new line in the end
