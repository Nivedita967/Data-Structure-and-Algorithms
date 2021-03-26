int minDifficultyNonRecursion(int* jobDifficulty, int jobDifficultySize, int d){
    int n = jobDifficultySize;
    if (d > n) return -1;
    // take an array of size day+1 and jobSizes+1
    int F[d+1][n+1];
    for(int i=0; i<=d; i++){
        for(int j=0; j<=n; j++){
            F[i][j] = 0;
        }
    }
    // FIRST DAY CALCULATIONS (base case calculations):
    // find maximum job difficulty from 0th index upto ith index
    // note: you can only have maximum difficulty of a job at ith index from 0 to i-1th index
    // this is due to the given requirement that for ith job to be completed, all 0 to i-1th job should be completed first
    // you can also think of this as making just 1 cut in jobDifficulty array and finding maximum on the left hand side of your cut and storing it at your current location, to be used for in future
    for (int i = 1; i <= n; i++){
        // find max between previous max and current value
        F[1][i] = MAX(F[1][i-1], jobDifficulty[i-1]);
    }

    // start by making at least 2 cuts, go upto d cuts (since we start with 1 and not 0)
    for (int i = 2; i <= d; i++) {
        // make all possible cuts from 2 until n
        for (int j = i; j <= jobDifficultySize; j++) {
            // assume result is MAXIMUM, so we can replace it with first minimum we find
            F[i][j] = INT32_MAX;
            int currMax = 0;
            // go from j until i
            for (int k = j; k >= i; k--) {
                currMax = MAX(currMax, jobDifficulty[k-1]);
                F[i][j] = MIN(F[i][j], F[i-1][k-1] + currMax);
            }
        }
    }
    return F[d][n];
}
