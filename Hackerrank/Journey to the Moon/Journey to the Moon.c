#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//function definition for making pairs
int FindP(int *P, int x)
{
    if(P[x] != x)
    {
        P[x] = FindP(P, P[x]);
    }
    return P[x];
}

// function for merging the pairs 
void MergeS(int *P, int *R, int *C, int A, int B)
{
    //comparing and merging
    if(R[A] < R[B]) {
        P[A] = B;
        C[B] += C[A];
    } else if(R[A] > R[B]) {
        P[B] = A;
        C[A] += C[B];
    } else {
        P[B] = A;
        R[A] += 1;
        C[A] += C[B];
    }
}



int main()
{
    //declaration of required arrays and variables
    int R[100000], P[100000], C[100000], i, N, I, A, B, UC;
    int M[100000], S[100000];
    unsigned long long result;

    //taking input of astronauts and no of pairs
    scanf("%d%d", &N, &I);
    for(i=0;i<N;i++) {
        P[i] = i;
        C[i] = 1;
        R[i] = 0;
    }
    //loop for inputting I times two space seperated astronauts ID's from same country
    for(i=0;i<I;i++) 
    {
        //inputting them
        scanf("%d%d", &A, &B);

        //function calls for finding pairs
        A = FindP(P, A);
        B = FindP(P, B);

        //checking if A is equal to B or not 
        if(A != B)
        {   
            //merging the pairs
             MergeS(P, R, C, A, B);  
        }
    }
    UC = 0;
    for(i=0;i<N;i++) 
    {
        if(P[i] == i)
        {
            M[UC++] = C[i];
        }
    }
    S[0] = M[0];
    for(i=1;i<UC;i++) 
    {
        S[i] = S[i-1] + M[i];
    }

    // initialsing result
    result = 0;

    //loop for counting the no of pairs
    for(i=0;i<UC-1;i++)
    {
        // counting the no of pairs
        A = M[i];
        B = S[UC-1] - S[i];
        result += A*B;
    }

    //printing the result
    printf("%llu", result);
    return 0;
}
