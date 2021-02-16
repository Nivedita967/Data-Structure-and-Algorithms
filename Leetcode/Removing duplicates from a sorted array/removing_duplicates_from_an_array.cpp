#include <iostream>
using namespace std;

int main()
{
	//variable declaration 
	int i, j, k, Size;
	
	//taking input of no of elements
	cout<<"\n Please Enter Number of elements in an array  :   ";
	cin>>Size;
	
	// taking inout of elements
	cout<<"\n Please Enter "<<Size<<" elements of an Array \n";
	int arr[Size];
	for (i = 0; i < Size; i++)
	{
    	cin>>arr[i];
   	}

	//loop to remove duplicate elements
	for (i = 0; i < Size; i++)
	{
		for(j = i + 1; j < Size; j++)
		{
    		if(arr[i] == arr[j])
    		{
    			for(k = j; k < Size; k++)
    			{
    				arr[k] = arr[k + 1];
				}
				Size--;
				j--;
			}
		}
	}
	
	//printing final array after removing duplicates
 	cout<<"\n Final Array after Deleteing Duplicate Array Elements is:\n";
 	for (i = 0; i < Size; i++)
  	{
 		cout<<arr[i]<<" ";
  	}
 	return 0;
}
