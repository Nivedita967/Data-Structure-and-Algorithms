def stockmax(p):
    ind_max = p.index(max(p)) #find the max price
    inv = sum(p[:ind_max]) #split the array before and after max price
    pf = len(p[:ind_max])*p[ind_max] - inv #buy all stocks before max price 
    if len(p[ind_max+1:]) > 0:
        pf += stockmax(p[ind_max+1:]) #then sell them at max price
    return pf
