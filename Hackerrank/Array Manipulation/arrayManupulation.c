#include <iostream>

using namespace std;

const int MAX = 1e7+2;

//An array used to capture the difference of an element
//compared to the previous element.
long long arr[MAX];


int main()
{
    int n, m;
    scanf("%d %d",&n,&m);


    for(int i=1;i<=m;++i){
        int a, b, k;
        scanf("%d %d %d",&a,&b,&k);

        //Adds "k" to all subsequent elements in the array
        arr[a] += k;
        //Subtracts "k" from all subsequent elements in the array
        arr[b+1] -= k;

    }


    long long x = 0,res=-(1LL<<60);
    for(int i=1;i<=n;++i){
        x += arr[i];

        //Storing the max value
        res = max(res,x);
    }

    //Printing the max value, res
    printf("%d\n",res);
    return 0;
}

