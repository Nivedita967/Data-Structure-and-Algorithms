#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Defining structure 
struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
//Swapping the values
void swap(triangle* a,triangle* b)
{
    triangle temp=*a;
    *a=*b;
    *b=temp;
}
//Comparing the triangles 
int cmp(triangle tr)
{
    int a=tr.a;
    int b=tr.b;
    int c=tr.c;
    return (a+b+c)*(a-b+c)*(a+b-c)*(-a+b+c);
}
void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    for(int i=0;i<n;i++)
    {
        int swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
        	//Comparing the values and sorting 
            if(cmp(tr[j])>cmp(tr[j+1]))
             //If condition satisfies then it will swap the values
             swap(&tr[j],&tr[j+1]);
            swapped=1;
        }
        if(swapped==0)
            break;
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	//Printing the swapped values.
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
/*
Input:- 

3
7 24 25
5 12 13
3 4 5

Ouput:- 

3 4 5
5 12 13
7 24 25

*/
