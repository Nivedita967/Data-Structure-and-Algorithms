t = int(input())
for _ in range(t):
    n,k,d = map(int, input().split())

    # Taking n integers and storing it in list
    arr = list(map(int, input().split()))

    # Finding sum of all elements inside array
    total = sum(arr)

    # Floor division would give the answer but
    # see to it that doesn't excede d, therefore
    # min is taken in between them
    print(min(total//k,d))