#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXL    26624

unsigned int MADD(unsigned int* pC, unsigned int* pB, unsigned int* pA, unsigned int n)
{
    unsigned int i,j,x;
    
    for (i=0; i<n; i++) pC[i] = pA[i]; //iterate through array
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++) //inner loop
        {
            if ((x = (pC[i+j] += pB[i]*pB[j])) < 10000) continue; //pass through/skip this iteration
            x /= 10000; pC[i+j+1] += x; pC[i+j] -= x*10000;            
        }
        if ((x = pC[i+j]) < 10000) continue;   //pass through/skip this iteration
        x /= 10000; pC[i+j+1] += x; pC[i+j] -= x*10000;             
    }
    n <<= 1; while (pC[n-1] == 0) n--; //left shifting n
    return n;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int N,m,n=1;
    unsigned int* p;
    unsigned int* pA;
    unsigned int* pB;
    unsigned int* pC;
    unsigned int A[MAXL];
    unsigned int B[MAXL];
    unsigned int C[MAXL];

    memset(pA=A, 0, sizeof(A));
    memset(pB=B, 0, sizeof(B));
    memset(pC=C, 0, sizeof(C));

    scanf("%d %d %d\n", pA, pB, &N);

    while (N-- > 2)
    {
        n = MADD(pC, pB, pA, n);
        p = pC; pC=pA; pA = pB; pB=p;
    }
    printf("%d", p[--n]);
    while (n > 0) printf("%04u", p[--n]);
    printf("\n");
    return 0;
}