from collections import Counter


# Complete the migratoryBirds function below.
def migratoryBirds(arr):
    m=[]
    c = dict(Counter(arr))
    for i in c.items():
        if i[1]==max(c.values()):
            m.append(i[0])
    return min(m)



if __name__ == '__main__':


    arr_count = int(input().strip())

    arr = list(map(int, input().split(' ')))
    result = migratoryBirds(arr)
    print(result)
