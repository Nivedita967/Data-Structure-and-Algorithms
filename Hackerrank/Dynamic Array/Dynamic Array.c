#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, q, o, x, y, ti, pi, la;
	int *a, *s;
	int **v;
	scanf("%d %d", &n, &q); //take inputs

    //declare dynamic arrays using malloc
	v = (int **)malloc(n * sizeof(int *)); 
	a = (int *)malloc(n * sizeof(int));
	s = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) //iterate through the array
	{
        //set default values
		s[i] = 1;
		v[i] = (int *)malloc(s[i] * sizeof(int));
		a[i] = 0;
	}
    la = 0;
	for (int i = 0; i < q; i++) //iterate through array
	{
		scanf("%d %d %d", &o, &x, &y); //take inputs
		ti = (x ^ la) % n;
		if (o == 1)
		{
			v[ti][a[ti]] = y;
			a[ti] ++;
			if (a[ti] == s[ti])
			{
 				s[ti] *= 2;
				v[ti] = realloc(v[ti], s[ti] * sizeof(int));
			}
		}
		else
		{
			pi = y % a[ti];
			printf("%d\n", v[ti][pi]);
			la = v[ti][pi];
		}
	}

    //free the allocated memories/pointers
	free(s);
	free(a);
	free(v);
	return 0;
}