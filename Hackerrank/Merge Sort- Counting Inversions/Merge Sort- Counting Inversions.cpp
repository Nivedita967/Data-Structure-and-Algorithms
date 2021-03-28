#include<iostream>
#include<cstdio>

using namespace std;

long long ans=0;

//function for merging
void mergei(int a[],int i,int j)
{
    int ni=((i+j)/2)+1,nj=j+1;
    int s=i;
    //new array
    int * arr = new int [j-i+1];
    j=ni;
    int k=0;
    
    //loop for merging the elements
    while(i<ni && j<nj)
    {
        if(a[i]<=a[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=a[j];
            ans+=(ni-i);
            j++;
        }
        k++;
    }
    
    //loops for side cases and if the element is left
    for(;i<ni;i++,k++)
      {  arr[k]=a[i];}
    for(;j<nj;j++,k++)
       { arr[k]=a[j];}
    for(k=0;s<nj;s++,k++)
        {a[s]=arr[k];}
        
    //deleting arr
    delete [] arr;
}

//function definition
void m_sort(int a[],int i,int j)
{
    if(i<j)
    {
        //recurcive calling of function
        m_sort(a,i,(i+j)/2);
        m_sort(a,((i+j)/2)+1,j);
        
        //calling mergei function to merge 
        mergei(a,i,j);
    }
}
int main()
{
    //declaration and input
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ans=0;
        scanf("%d",&n);
        
        //creating array dynamically
        int * a = new int[n];
        
        //taking input
        for(int i=0;i<n;i++)
           { scanf("%d",&a[i]);}
           
        //calling funtion to perform a merge sort 
        m_sort(a,0,n-1);
        //printing
        cout<<ans<<endl;
    }
    return 0;
}