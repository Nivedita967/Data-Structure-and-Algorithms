// C program for merge sort - counting inversions

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define RUN_CASES(VAR) int VAR##_total; scanf("%d", & VAR##_total); \
    for(int VAR=1; VAR<=VAR##_total; ++VAR)

typedef unsigned long long ull;

ull merge(int *a, const int first, const int last)
{
    //if last - first is 1 then return 0
    if (last - first == 1)
        return 0;
    //if last - first is not 1
    if (last - first == 2)
    {
        if (a[first + 1] < a[first])
        {
            //swap a[first] with a[first + 1]
            int tmp = a[first];
            a[first] = a[first + 1];
            a[first + 1] = tmp;

            return 1;
        }

        return 0;
    }

   //middle element
    int m = first + (last - first) / 2;

    ull inverse = merge(a, first, m);
    inverse += merge(a, m, last);

    int lo = first, hi = m;
    int t = first;
   //create new array temp
    static int temp[100001];

    while (lo < m && hi < last)
    {
        //if a[lo] <= a[hi] then store a[lo++] in temp
        if (a[lo] <= a[hi])
        {
            temp[t++] = a[lo++];
            continue;
        }

        temp[t++] = a[hi++];
        inverse += m - lo;
    }

    while (lo < m) temp[t++] = a[lo++];
    while (hi < last) temp[t++] = a[hi++];

    for (int j = first; j < last; ++j)
        a[j] = temp[j];
   
   //return inverse as result
    return inverse;
}

int main()
{
#ifdef _DEBUG
    char FNAME[250];
    strcpy(FNAME, __FILE__);
    strcpy(strchr(FNAME, '.'), ".txt");
    freopen(FNAME, "rt", stdin);
#endif

    RUN_CASES(test_case)
    {
        int a[100001];
        //accept array and also number of array elements
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[j]);

        printf("%llu\n", merge(a, 0, n));
    }
}

