if __name__ == "__main__":
    N, Q = map(int, input().strip().split(' ')) #Taking input
    sequences = [[] for _ in range(N)] #Creating a 2D array
    last_answer = 0 

    for q in range(Q):
        q_type, x, y = map(int, input().strip().split(' ')) #Spliting q_type, x and y
        seq_num = (x ^ last_answer) % N #Formula given in problem statement

        if q_type == 2:
            last_answer = sequences[seq_num][y % len(sequences[seq_num])] #Updating lastAnswer
            print(last_answer) #Printing lastAnswer
        else:
            sequences[seq_num].append(y) #Appending y