n=input()+1 #initially add one because the number has to be greater
while len(set(str(n))) < 4:n+=1 #now keep adding one until number is greater and unique
print n