import functools

def sortLexo(my_list):
    sorted_list = sorted(a_list, key = lambda s : s.lower())
    for x in sorted_list:
        print(x)
  
def sortLexoreverse(my_list):
    sorted_list=sorted(my_list, key = lambda x : 255-ord(x))
    for x in sorted_list:
        print(x)
        
def countDistinct(s):
    # Initialize dictionary
    m = {}
    for i in range(len(s)):
        # Count distinct characters
        if s[i] not in m:
            m[s[i]] = 1
        else:
            m[s[i]] += 1
    return len(m)
 
# Function to perform sorting
def compare(a, b):
    if (countDistinct(a) == countDistinct(b)):
        # Check if size of string 1
        # is same as string 2 then
        # return false because should not be placed before s2
        return (len(b) - len(a))

    else:
        return (countDistinct(a) - countDistinct(b))

def sortLen(my_list):
    sorted_list)=my_list.sort(key=len)
    for x in sorted_list:
        print(x)


if __name__ == '__main__': 

    
    my_list=[]
    n = int(input("Enter number of elements : ")) 

    for i in range(0, n): 
        ele = int(input()) 
        my_list.append(ele)

    sortLexo(my_list) 
    sortLexoreverse(my_list)
    lst)=(*sorted(my_list , key = functools.cmp_to_key(compare)), sep = ' ')
    for x in lst:
       print(x)
    sortLen(my_list)
