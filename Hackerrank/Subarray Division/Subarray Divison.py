def getWays(squares, d, m):
    tp = (len(squares)-m) + 1 #total number of pieces possible
    return len([1 for i in range(tp) if sum(squares[i:i+m])==d])