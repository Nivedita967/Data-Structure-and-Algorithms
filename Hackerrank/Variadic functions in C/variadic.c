
int  sum (int count,...) { //Taking inputs as count variable and epsilon
va_list ap; //Adding variable list 
int i,s=0; //Declaring variables
va_start(ap,count); //Using variabl start function 
for(i=0;i<count;i++)
{
    s=s+va_arg(ap,int); //Loop
}
va_end(ap); //Using variable end function
return s;
}

int min(int count,...) {
va_list ap;  //Using variable list
int i,min=0,temp,f=0; //Declaring variables
va_start(ap,count); //Using variable start function
for(i=0;i<count;i++)
{
    temp=va_arg(ap,int); //For loops
    if(f==0) //Codiiton 
    {
        min=temp; //Assigining min value
        f=1;
    }
    if(temp<min)
        min=temp; // Assigning min value

}
return min;

}

int max(int count,...) {
va_list ap; //Assigning va list 
int i,max=0,temp,f=0; //Declaring variables
va_start(ap,count); //using va start function 
for(i=0;i<count;i++)
{
    temp=va_arg(ap,int); //storing data in temp 
    if(f==0)
    {
        max=temp; // storing data in max
        f=1; //Assigning f = 1
    }
    if(temp>max)
        max=temp; // storing data in max
        }
return max;
}

