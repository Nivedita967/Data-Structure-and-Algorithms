def merge_the_tools(string, k):
    # your code goes here
    # will store string of size k
    merged_list = []
    number = len(string)//k

    # Loop for appending string of size k
    for i in range(0,len(string),k):
        merged_list.append(string[i:i+k])
    
    # Loop for printing the elements of merged lists
    for i in merged_list:
        print(remove(i))

# Function to have only unique elements
def remove(arr):
    return ''.join(dict.fromkeys(arr))

# Internal HackerRank code (already given)
if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)