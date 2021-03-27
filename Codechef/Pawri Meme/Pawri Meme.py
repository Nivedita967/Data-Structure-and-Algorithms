n=int(input()) # take input from the user
i=1;
while i<=n :
    string = input()
    substring = "party"
    replacing_string = "pawri"
    print(string.replace(substring,replacing_string)) # change each of its substrings that spells "party" to "pawri" 
    i=i+1
    
'''
Example Input:
3
part
partypartiparty
yemaihuyemericarhaiauryahapartyhorahihai
----------------------------------------
Example Output:
part
pawripartipawri
yemaihuyemericarhaiauryahapawrihorahihai
'''
