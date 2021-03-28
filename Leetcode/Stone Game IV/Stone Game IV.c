/*
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile.  On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n. Return True if and only if Alice wins the game otherwise return False, assuming both players play optimally.

*/
bool winnerSquareGame(int n){
    // IF starting from N, there is a value of k>=1 and kk <=n that n-kk make to loose bob, Alice win.
    int i,k, *dp = (int*)calloc(sizeof(int), (n+1));
    // use a support array called dp, & save 0 or 1 in dp[N], if with value N there is a win or a loose.
    for(i=1; i<=n; ++i)
        for(k=1; (k*k)<=i; k++)
        // Starting from 1 to N, build the support array dp, having in the end the desiderd answer in dp[N]
            if(dp[i - (k*k)] == 0){
                dp[i] = 1;
                break;
            }
    return dp[--i];
}