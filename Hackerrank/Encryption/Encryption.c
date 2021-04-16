/* Program to Encrypt the string by finding the two square root where the
length of the original string exists and take them as row and columns respectively
and encrypt it
*/
//function which encrypt the string
char* encryption(char* s)
{
// r and c are for rows and columns
int i,r,c,j,k=0,p=0;
//string in which encrypted string will exist to return
char *str;
//until i is less then 10 run the loop to find the rows and columns
for(i=1;i<10;i++)
{
     // if length of string is a perfect square then r and c both will be same
     if(i*i>=strlen(s))
    {
        r=i;
        c=i;
        break;
    }
    // if length of string is not a prefect square then assign lower square in r and upper in c
    else if(i*(i+1)>=strlen(s)){
    r=i;
    c=i+1;
    break;
    }

}
//dynamically giving memory
str=(char*)malloc(sizeof(char)*strlen(s)+c);
// until i is less than columns run the loop
for(i=0;i<c;i++)
{
    //assign s[i] th value in str[k] value and increment k by 1
    str[k]=s[i];
    k++;
    // assign the value of i in p so it can be used without any loose of data
    p=i;
    // until j less than rows-1 run the loop
    for(j=0;j<r-1;j++)
    {
        // add columns in p
         p+=c;
         // if p less than length of string
        if(p<strlen(s))
        {
             //assign s[p] th data in str[k] index
             str[k]=s[p];
             k++;
        }
        //else break
        else
        break;
    }
    //at the end of loop assign space ' ' in str[k] th index and increment k by 1
    str[k]=' ';
    k++;
}
/* at the end of then program assign 0 or NULL in str[k] so it can be clarify for function to
that when to stop printing character */
str[k]=0;
 return str;

}
/*
Example:
Input:  haveaniceday
Output: hae and via ecy

Time complexity: O(2N)
*/
