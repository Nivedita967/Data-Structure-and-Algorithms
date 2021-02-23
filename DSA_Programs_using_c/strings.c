#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct string
{
    char *s;
    int size;
};
void Lengthstr(struct string str)
{
    int i;
    for(i=0;str.s[i]!='\0';i++)
    {
    }
    printf("Length is %d\n",i);
}
void changingcase(struct string str)
{
    int i;
    for(i=0;str.s[i]!='\0';i++)
    {
        str.s[i]=str.s[i]+32;
    }
    printf("%s\n",str.s);
}
void changingmixedcase(struct string str)
{
    int i;
    for(i=0;str.s[i]!='\0';i++)
    {
        if(str.s[i]>=65&&str.s[i]<=90)
            str.s[i]+=32;
        else if(str.s[i]>='\a'&&str.s[i]<=122)
            str.s[i]-=32;
    }
    printf(str.s);
}
void CoutingVowelsandconsonents(struct string str)
{
    int i,Vcount=0,Ccount = 0;
    for(i=0;str.s[i]!='\0';i++)
    {
        if(str.s[i]=='a'||str.s[i]=='e'||str.s[i]=='i'||str.s[i]=='o'||str.s[i]=='u'||str.s[i]=='A'||str.s[i]=='E'
           ||str.s[i]=='I'||str.s[i]=='O'||str.s[i]=='U')
        {
            Vcount++;
        }
        else if((str.s[i]>=65&&str.s[i]<=90)||(str.s[i]>=97&&str.s[i]<=122))
            {
                Ccount++;
            }
    }
    printf("Vowels: %d, Consonents: %d\n",Vcount,Ccount);
}
void Countingnumberofwords(struct string str)
{
    int i,word = 0;
    for(i=0;str.s[i]!='\0';i++)
    {
        if(str.s[i]==' '&&str.s[i-1]!=' ')
            word++;
    }
    printf("No.of Words: %d ",word+1);
}
void ValidateaString(struct string str)
{
    int i,count=0;
    for(i=0;str.s[i]!='\0';i++)
    {
        if(!(str.s[i]>65&&str.s[i]<=90)&&!(str.s[i]>=97&&str.s[i]<=122)&&!(str.s[i]>=48&&str.s[i]<=57)&&!(str.s[i]>=48
        && str.s[i]>=48&&str.s[i]<=57)){
            count++;
    	}
    }
    if(count > 0){
        printf("InValid String");
    }
    else
        printf("valid String");
}
void Reversing(struct string str)
{
    char *str2=(char*)malloc(str.size*sizeof(char));
    int i,j;
    for(i=0;str.s[i]!='\0';i++)
    {
    }
    i = i-1;
    for(j=0;i>=0;i--,j++)
    {
        str2[j]=str.s[i];
    }
    str2[j]='\0';
    printf("%s",str2);
}
void Reversing2(struct string str)
{
    int i,j;
    char t;
    for(j=0;str.s[j]!='\0';j++)
    {
    }
    j = j-1;
    for(i=0;i<j;i++,j--)
    {
        t=str.s[i];
        str.s[i]=str.s[j];
        str.s[j]=t;
    }
    printf("%s",str.s);
}
void ComparingStr(struct string str)
{
    char *B;
    int size1;
    printf("Enter size of second alphabet: ");
    scanf("%d",&size1);
    B = (char*)malloc(size1*sizeof(char));
    printf("Enter the second word: \n");
    scanf("%s",B);
    int i,j;
    for(i=0,j=0;str.s[i]!='\0';i++,j++)
    {
        if(str.s[i]!=B[j])
            break;
    }
    if(str.s[i]==B[j])
        printf("Equal");
    else if(str.s[i]<B[j])
        printf("Smaller");
    else
        printf("Greater");
    free(B);
    B=NULL;
}
void checkingpalindrome(struct string str)
{
    int i,j;
    for(j=0;str.s[j]!='\0';j++)
    {
    }
    j = j-1;
    for(i=0;i<j;i++,j--)
    {
        if(str.s[i]!=str.s[j])
        {
            printf("The string is not a palindrome.");
            return;
        }
    }
    printf("It's a palindrome.");
}
void Duplicate(struct string str)
{
int i,j;

int count=1;
for (i=0;str.s[i]!='\0';i++)
{
    if(str.s[i]!='0')
    {
        for (j=i+1;str.s[j]!='\0';j++)
        {
            if(str.s[i]==str.s[j])
            {
                count++;
                str.s[j]='0';
            }
        }
        if(count>1)
        {
            printf("\n %c occurs %d times.",str.s[i],count);
            count = 1;
        }
    }
}
}
void Duplicatehash(struct string str)
{
    int i;

    int *H;
    H = (int *)malloc((26)*sizeof(int));
    for(i= 0;i<26;i++)
        H[i]=0;
    for(i=0;str.s[i]!='\0';i++)
    {
        H[str.s[i]-97]+=1;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
            printf("%c occurs %d times.\n",i+97,H[i]);
    }
    free(H);
    H=NULL;
}
void perm(struct string str,int k)
{
    static int A[10]={0};
    static char Res[10];
    int i;
    if(str.s[k]=='\0')
    {
        Res[k] = '\0';
        printf(Res);
        printf(" ");
    }
    else{
        for(i=0;str.s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                Res[k]=str.s[i];
                A[i]=1;
                perm(str,k+1);
                A[i]=0;
            }
        }
    }
}
void swap(char *A,char *B)
{
    char temp;
    temp = *A;
    *A = *B;
    *B = temp;
}
void permswap(struct string str,int l,int h)
{
    int i;
    if(l==h)
    {
        printf(str.s);
        printf(" ");
    }
    else
    {
        for(i=l;i<=h;i++)
        {
            swap(&str.s[l],&str.s[i]);
            permswap(str,l+1,h);
            swap(&str.s[l],&str.s[i]);
        }
    }
}
int main()
{
    struct string str;
    printf("Enter the character length: ");
    scanf("%d",&str.size);
    printf("Enter the sring: ");
    str.s=(char *)malloc(str.size*sizeof(char));
    scanf("%s",str.s);
    int ch;
    do{
        printf("\n1. Find Length of the string: \n");
        printf("2. Changing case upper to lower: \n");
        printf("3. Mixed alphabets changing to its opposite case: \n");
        printf("4. Counting vowels and consonents: \n");
        printf("5. Counting No.of words: \n");//error
        printf("6. Validate a string: \n");//error
        printf("7. Reversing a string: \n");
        printf("8. Reversing a string Method-2: \n");
        printf("9. Comparing strings\n");
        printf("10. Checking whether it is palindrome or not.\n");
        printf("11. Finding duplicates in a string\n");
        printf("12. Finding duplicates in a string using hash table\n");
        printf("13. Permutations of a string method - 1\n");
        printf("14. Permutations of a string method - 2\n");
        printf("15. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: Lengthstr(str);
                break;
            case 2: changingcase(str);
                break;
            case 3: changingmixedcase(str);
                break;
            case 4: CoutingVowelsandconsonents(str);
                break;
            case 5: Countingnumberofwords(str);
                break;
            case 6:ValidateaString(str);
                break;
            case 7:Reversing(str);
                break;
            case 8: Reversing2(str);
                break;
            case 9: ComparingStr(str);
                break;
            case 10: checkingpalindrome(str);
                break;
            case 11:Duplicate(str);
                break;
            case 12:Duplicatehash(str);
                break;
            case 13:perm(str,0);
                break;
            case 14:permswap(str,0,2);
                break;
        }
    }while(ch<15);
    free(str.s);
    str.s = NULL;
    return 0;
}