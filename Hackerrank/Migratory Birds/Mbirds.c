//Time Complexity O(n)
int migratoryBirds(int arr_count, int* arr) 
{
    int count[arr_count], max=0, index;  
    for(int i=0; i<arr_count; i++) //Array for counting purpose
        count[i]=0;
    for(int i=0; i<arr_count; i++) //Counting each term
        count[arr[i]]++;
    for(int i=0; i<arr_count; i++) //Finding the max one
    {
        if(count[i]>max)
        {
            max = count[i];
            index = i;
        }
    }
    return index;        
}
