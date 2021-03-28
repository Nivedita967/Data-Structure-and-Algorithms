//Problem:https://codeforces.com/problemset/problem/1475/A
include <stdio.h>
int main()
{
    int t;  scanf("%d" ,&t);
    long long temp;
    int x;
    while (t --)
    {
      scanf("%d" ,&temp);
        x = 0;
        //return Yes if number have odd divisor else 
        //half the number until it is not divisible completely by 2
        //then check for YES or NO
        if (temp % 2 != 0)
        {
            printf("YES\n");
        }
        else
        {
            for (int i = 0 ; i < temp ; i)
            {
                temp /= 2;
                if (temp % 2 != 0 && temp != 1)
                {
                    x = 1;
                    break;
                }
            }
            if (x == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
