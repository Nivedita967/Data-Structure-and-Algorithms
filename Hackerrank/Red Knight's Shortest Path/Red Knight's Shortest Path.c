/*
In ordinary chess, the pieces are only of two colors, black and white. In our version of chess, we are including new pieces with unique movements. One of the most powerful pieces in this version is the red knight.
The board is a grid of size . Each cell is identified with a pair of coordinates , where  is the row number and  is the column number, both zero-indexed. Thus,  is the upper-left corner and  is the bottom-right corner.

Complete the function printShortestPath, which takes as input the grid size , and the coordinates of the starting and ending position  and  respectively, as input. The function does not return anything.

Given the coordinates of the starting position of the red knight and the coordinates of the destination, print the minimum number of moves that the red knight has to make in order to reach the destination 
and after that, print the order of the moves that must be followed to reach the destination in the shortest way. If the destination cannot be reached, print only the word "Impossible".

Note: There may be multiple shortest paths leading to the destination. Hence, assume that the red knight considers its possible neighbor locations in the following order of priority: 
UL, UR, R, LR, LL, L. In other words, if there are multiple possible options, the red knight prioritizes the first move in this list, as long as the shortest path is still achievable. Check sample input  for an illustration.

*/
int ind = 0;
int array[40000]; 
void recursive(int x,int y,int i_end,int j_end)
{
	if(i_end<x)
    {
        if(j_end<y)
        {
            x = x-2;
            y = y-1;
            array[ind++] = 1;//printf("UL ");
            recursive(x,y,i_end,j_end);
        }
        else 
        {
            x = x-2;
            y = y+1;
            array[ind++] = 2;//printf("UR ");
            recursive(x,y,i_end,j_end);
        }
            
    }
	else if(i_end>x)
	{
		if(j_end<y)
        {
            x = x+2;
            y = y-1;
            array[ind++] = 5;//printf("LL ");
            recursive(x,y,i_end,j_end);
        }
        else
		{
            x = x+2;
            y = y+1;
            array[ind++] = 4;//printf("LR ");
            recursive(x,y,i_end,j_end);
        }
        
	}
	else    //moving horizontally
	{
		if(j_end<y && abs(j_end-y)%2 == 0)
        {
                
                y = y-2;
                array[ind++] = 6;//printf("L ");
                recursive(x,y,i_end,j_end);
        }
        else if(j_end>y && abs(j_end-y)%2 == 0)
        {
                
                y = y+2;
                array[ind++] = 3;//printf("R ");
                recursive(x,y,i_end,j_end);
        }
		else if(abs(j_end-y)%2 != 0) 
		{
			ind = 0;
			printf("Impossible\n");
	    }
	}
}
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    //static int x = i_start;
    //static int y = j_start;
    int i_dif = abs(i_start-i_end);
    int j_dif = abs(j_start-j_end);
    
    if(i_dif%2 != 0)
         printf("Impossible\n");
    else if(i_dif == 0 && j_dif == 0)
        return;
    else
		recursive(i_start,j_start,i_end,j_end);
}
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
   
}
int main() {
    int n; 
    scanf("%i", &n);
    int i_start; 
    int j_start; 
    int i_end; 
    int j_end; 
    scanf("%i %i %i %i", &i_start, &j_start, &i_end, &j_end);
    if(n<=i_start || n<=i_end || n<=j_start || n<=j_end ||i_start<0 || j_start<0 || i_end<0 ||j_end<0)
        return 0;
    if(n>200 || n<5)
        return 0;
    printShortestPath(n, i_start, j_start, i_end, j_end);
	if(ind>0)
		printf("%d\n",ind);
    
    insertionSort(array,ind);
	for(int l=0;l<ind;l++)
    {
		if(array[l] == 1)
			printf("UL ");
		else if(array[l] == 2)
			printf("UR ");
		else if(array[l] == 3)
			printf("R ");
		else if(array[l] == 4)
			printf("LR ");
		else if(array[l] == 5)
			printf("LL ");
		else if(array[l] == 6)
			printf("L ");
	}
    return 0;
}