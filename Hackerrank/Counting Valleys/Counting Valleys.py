#Problem:https://www.hackerrank.com/challenges/counting-valleys/problem

#Approach:We initialise valley and sea_level as 0. And we count how many times the Up or Down steps were in the path.
#A valley always ends with a step up to a sea level. Sea level is 0. Thus we say when the sea level is 0 and
#the character in the PATH is "U", we increment the valley by 1. At the end return how many times the valleys were hiked.
  
def count_valleys(n, steps):
    num_valleys = 0        # number of valleys
    level = 0              # starts at sea level
    for d in steps:
        if d == 'U':       # going upslope
            level += 1
        else:              # going downslope
            if level == 0:
                num_valleys += 1
            level -= 1
    return num_valleys

n = input()
steps = input()
result = count_valleys(n, steps)
print(result)
