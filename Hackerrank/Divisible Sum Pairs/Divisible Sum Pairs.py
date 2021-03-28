def divisibleSumPairs(n, k, ar):
    # Complete this function
    count = 0 #initialize variable
    for i in range(n-1): #iterate 
        j = i+1
        while j < n:
            if ((ar[i] + ar[j]) % k) == 0:  #check if condition satisfied
                count += 1 #increment count
            j += 1
    return count