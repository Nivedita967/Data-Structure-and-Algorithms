#include <stdio.h>

int main()
{
  //declaraing all the variables
  int i,n,amt,nof100,nof50,nof10,nof5,nof2,nof1,total,remain;

  //taking input of the number N
  scanf("%d",&n);

  //loop for finding smallest no of notes
  for(i=0;i<n;i++)
  {
        // inputting the amount
        scanf("%d",&amt);

        //checking the no of 100 rs note required
        nof100=amt/100;
        remain=amt%100;

        //checking the no of 50 rs note required
        nof50=remain/50;
        remain=remain%50;

        //checking the no of 10 rs note required
        nof10=remain/10;
        remain=remain%10;

        //checking the no of 5 rs note required
        nof5=remain/5;
        remain=remain%5;

        //checking the no of 2 rs note required
        nof2=remain/2;
        remain=remain%2;

        //checking the no of 1 rs note required
        nof1=remain/1;

        // total no of notes
        total=nof100+nof50+nof10+nof5+nof2+nof1;

        //printing output
        printf("%d\n",total);
  }
	return 0;
}
