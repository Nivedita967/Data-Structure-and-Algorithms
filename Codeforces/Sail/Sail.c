# include <stdio.h>
main()
{
long long int t,x1,x2,y1,y2,i;
char c;
scanf("%I64d %I64d %I64d %I64d %I64d\n",&t,&x1,&y1,&x2,&y2); //take inputs, I64 is just for long long int 
 
for(i=1;i<=t;i++) //iterate through seconds
{
    c=getchar(); //take character input 

    //check which direction
    if(c=='N'){if(y2>y1)y1++;}
    else if(c=='S'){if(y2<y1)y1--;}
    else if(c=='E'){if(x2>x1)x1++;}
    else if(c=='W'){if(x2<x1)x1--;}
    if(x1==x2 && y1==y2){printf("%I64d",i);return 0;}
}
printf("-1"); //it nothing matches, default output
return 0;
}