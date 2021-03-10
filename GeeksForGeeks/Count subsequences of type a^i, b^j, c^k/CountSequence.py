# Python 3 program to count subsequences of the form 
# a ^ i b ^ j c ^ k   
# Returns count of subsequences of the form a ^ i b ^ j c ^ k 

def countSubsequences(s): 
  
    # Initialize counts of different subsequences by different 
    # combination of 'a' 
    countofa = 0
  
    # Initialize counts of different subsequences by different 
    # combination of 'a' and 'b'
    countofb = 0
  
    # Initialize counts of different subsequences by different 
    # combination of 'a', 'b' and 'c'
    countofc = 0
  
    # Traverse all characters of given string 
    for i in range(len(s)): 
      
       # If character is 'a' then it can be at the beginning and 
       # somewhere in the middle.
       # So count number of 'a' 
        if (s[i] == 'a'): 
            countofa = (1 + 2 * countofa) 
  
       # If character is 'a' and 'b' then different
       # combinations exist
       # So count number of 'a' and 'b'
        elif (s[i] == 'b'): 
            countofb = (countofa + 2 * countofb) 
  
        # If character is 'a', 'b' and 'c' then different
       # combinations exist
       # So count number of 'a', 'b' and 'c'
        elif (s[i] == 'c'): 
            countofc = (countofb + 2 * countofc) 
  
    # return the answer which is stored in c 
    return countofc 
  
# Driver code 
if __name__ == "__main__": 
    string = input('Enter the string')
    print(countSubsequences(string))

    