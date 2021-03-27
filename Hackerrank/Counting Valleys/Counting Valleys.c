#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
 {
     //declarations and inputs
    int num,i,valley=0;
    scanf("%d",&num);
    char steps[num];
    scanf("%s",steps);
    int sea=0;
    
    //loop for counting no of valleys
    for(i=0;i<num;i++)
    {
        if(sea==0 && steps[i]=='D')
         {   valley++;}
        if(steps[i]=='U')
          {  sea++;}
        else
           { sea--;}
    }
    //printing valleys
    printf("%d",valley);
    return 0;
}