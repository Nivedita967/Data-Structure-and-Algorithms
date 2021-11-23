a = input()            # Taking user input, the string of 5 digits
s = 0
for c in a:
    s += int(c)        # Converting every digit to integer and adding it to final sum
print(s)               # Printing the Final Sum
