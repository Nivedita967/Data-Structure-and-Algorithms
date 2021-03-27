def redJohn(n):
    # n is the length of 4 X n wall
    result, combos = 0, 1
    #  because of 4 X n wall
    for i in range(n // 4):
        combos += (math.factorial(n - 3 * (i+1)) / (math.factorial(n - 4 * (i+1)) * math.factorial(i+1)))
    for j in range(2, int(combos + 1)):
        prime = True
        # if j % 2 gets 0 then it is not a prime
        if j != 2 and j % 2 == 0:
            prime = False
        else:
            for k in range(3, 1 + round(j**0.5), 2):
                # Prime number is only divisible by 1 & itself
                if j % k == 0:
                    prime = False
        # increment the result if Prime
        result += 1 if prime else 0
    return result