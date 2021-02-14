def merge_the_tools(string, k):
    # your code goes here
    merged_list = []
    number = len(string)//k
    for i in range(0,len(string),k):
        merged_list.append(string[i:i+k])
    
    for i in merged_list:
        print(remove(i))

def remove(arr):
    return ''.join(dict.fromkeys(arr))

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)