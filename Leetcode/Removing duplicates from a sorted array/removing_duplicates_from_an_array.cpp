#include <iostream>
using namespace std;

int main()
{
	int i, j, k, Size;

	cout<<"\n Please Enter Number of elements in an array  :   ";
	cin>>Size;

	cout<<"\n Please Enter "<<Size<<" elements of an Array \n";
	int arr[Size];
	for (i = 0; i < Size; i++)
	{
    	cin>>arr[i];
   	}

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

 	cout<<"\n Final Array after Deleteing Duplicate Array Elements is:\n";
 	for (i = 0; i < Size; i++)
  	{
 		cout<<arr[i]<<" ";
  	}
 	return 0;
}
