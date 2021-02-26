t = int(input())
for i in range(t):    # Take user input
    n = int(input())
    count = 0
    while(n >= 100):  # Calculating 100 Rupee notes
        n -= 100
        count += 1
    while(n >= 50):   # Calculating 50 Rupee notes
        n -= 50
        count += 1
    while(n >= 10):   # Calculating 10 Rupee notes
        n -= 10
        count += 1
    while(n >= 5):    # Calculating 5 Rupee notes
        n -= 5
        count += 1
    while(n >= 2):    # Calculating 2 Rupee notes
        n -= 2
        count += 1
    while(n >= 1):    # Calculating 1 Rupee notes
        n -= 1
        count += 1
    
    print(count)