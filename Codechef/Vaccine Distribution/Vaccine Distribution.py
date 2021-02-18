# importing ceil from math library
from math import ceil

for _ in range(int(input())):
    # reading total people and max vaccination in one day
    n,d=map(int, input().split())
    
    # ages of all people
    age = list(map(int, input().split()))
    
    # both variables count people at risk and people not at risk
    risk = 0
    not_risk =0
    
    for i in age:
        # if age greter than or equal to 80 and less than and equal to 9 people are at risk otherwise not
        if i>=80 or i<=9:
            risk+=1
        else:
            not_risk+=1
            
    # calculating days to vaccinate risked people
    days_for_risk = ceil(risk/d)
    
    # calculating days to vaccinate people not at risk
    days_for_not_risk = ceil(not_risk/d)
    
    # printing the total days
    print(days_for_risk + days_for_not_risk)
