// C program to find couples holding hands

#define SIZE 60

//creating two arrays pair and position
int pair[SIZE];
int position[SIZE];

int minSwapsCouples(int* row, int rowSize){
    int count = 0;
    for (int i = 0; i < SIZE; i += 2) {
        //store i+1 in first element and i in the next
        pair[i] = i + 1;
        pair[i+1] = i;
    }
    for (int i = 0; i < rowSize; i++) {
        //store i in position array
        position[row[i]] = i;
    }
    
    for (int i = 0; i < rowSize; i += 2) {
        if (row[i + 1] != pair[row[i]]) {
            //increament count
            count++;
            int pos = position[pair[row[i]]];
            position[row[i + 1]] = pos;
            //swap row[pos] with row[i+1]
            int temp = row[pos];
            row[pos] = row[i+1];
            row[i+1] = temp;
            position[pair[row[i]]] = i + 1;
        }
    }
    //return answer
    return count;
}

