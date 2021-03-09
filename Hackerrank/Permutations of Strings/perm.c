#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s,int x,int y)
{
    char *temp; //Creting tempary char pointer
    temp = s[x]; // Swapping  
    s[x] = s[y]; //Swapping
    s[y] = temp; //swapping
}

void reverse(char **s,int x, int y)
{
    
    while(x<y) //loop
    {
     swap(s,x,y); //function calling
        x++; //incrementing x
        y--; // decrementing y
    }
}

int next_permutation(int n, char **s)
{
    int i,inv=-1; // Initializing values
    for(i=0;i<n-1;i++)
    {
        if(strcmp(s[i],s[i+1]) < 0) //condition
        {
            inv = i; //storing i int inv
        }
    }
    if(inv == -1) return 0; //returning zero if conditon satisfy
    for(i=n-1;i>inv;i--)
    {
        if(strcmp(s[inv],s[i]) < 0)
        {
            swap(s,inv,i); //function calling if conditon satisfy
            break; 
        }
    }
    reverse(s,inv+1,n-1); //function calling
    return 1; 
}
int main()
{
	char **s; 
	int n;
	scanf("%d", &n); //Taking the user input
	s = calloc(n, sizeof(char*)); //Creating memory dynamically
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char)); // Creating memory dynamically individually
		scanf("%s", s[i]); // Storing char values in the array
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' '); //Printing the result when condition becomes true 
	} while (next_permutation(n, s)); //Fuction calling
	for (int i = 0; i < n; i++)
		free(s[i]); //Deleting the memory.
	free(s); // delete the memory
	return 0;
}
