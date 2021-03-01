#include <iostream>

using namespace std;

int main()
{
    //declaring variables
   int d,c,t,t1,t2,a1,a2,a3,b1,b2,b3,res1,res2;

   //inputting no of test cases
   cin>>t;

   //loop for running test cases
   while(t--)
   {
    //inputting delivery charge, coupon, item prices 
     cin>>d>>c;
     cin>>a1>>a2>>a3;
     cin>>b1>>b2>>b3;
   
   //case 1
   t1=a1+a2+a3;
   t2=b1+b2+b3;
    res1=t1+t2+2*d;

    //case2
    if(t1<150)
        t1=t1+d;
    if(t2<150)
        t2=t2+d;

    //cost after taking coupon
    res2=t1+t2+c;

    //checking which costs more and printing accordingly
    if(res2<res1)
    {
        cout<<"YES"<<endl;
    }    
    else 
    {
        cout<<"NO"<<endl;
    }
}

    return 0;
}