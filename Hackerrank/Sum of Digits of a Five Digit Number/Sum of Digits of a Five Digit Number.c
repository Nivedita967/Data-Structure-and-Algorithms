#include <stdio.h>
#include <stdlib.h>

int main()
{
	  int sum = 0;
    for (int i = 0; i < 5; i++) 
    {
      char c;
      scanf("%c",&c);              // Reading every character of the number one by one
      sum += (c-48);               // Converting the character into number using ascii values and adding it to the final sum
    }
    printf("%d",sum);              // Displaying the result
}
