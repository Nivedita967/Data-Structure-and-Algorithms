//C program for Recursive Digit Sum
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100001

int sum_digits(char *value_string, long long int value_int, int use_string, int k)
{
    long long int value = 0;

    if(use_string == 1)
    {
        for(int i = 0; i < strlen(value_string); ++i)
        {    //store the concatenate string in value
            value += value_string[i] - '0';
        }

        value *= k;
        //return answer
        return sum_digits(value_string, sum_digits(value_string, value / 10, 0, 1) + value % 10, 0, 1);
    }
    else
    {
        value = value_int;
         //if value<10 and k=1 then simply return value
        if(value < 10 && k == 1)
        {
            return value;
        }
        else
        {
            return sum_digits(value_string, sum_digits(value_string, value / 10, 0, 1) + value % 10, 0, 1);
        }
    }
}

int main() {

    long long unsigned int n, k;
    char value[N_MAX] = {0, };
    char c;
    int index = 0;

    while((c=getchar()) != ' ' && c != EOF)
    {   
        if(index > N_MAX)
        {
            return -1;
        }

        value[index++] = c;  
    }

    scanf("%lld", &k);

    printf("%d", sum_digits(value, -1, 1, k));

    return 0;
}

