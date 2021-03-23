
//C program to sort integers by the power value
struct am{int number, val;};

int cmp(const void *x, const void *y){
    return ((struct am*)x)->val - ((struct am*)y)->val;
}

int getKth(int lo, int hi, int k){
    //store the calculated values, to avoid recalculation.
    struct am *result = (struct am*)malloc(sizeof(struct am)*((hi-lo)+1));
    int count = 0;
    for(int i = lo;i<=hi;i++){
        int value = i;
        int power = 0;
        while(value!=1){
            //If divisible by two, divide the number by 2.
            value = value%2==0 ? value/2 : value*3+1;
            power++;
        }
        result[count].val = power;
        result[count].number = i;
        //Increase the counter
        count++;
    }
    qsort(result, count, sizeof(const struct am), cmp);
    //Return result
    return result[k-1].number;
}

