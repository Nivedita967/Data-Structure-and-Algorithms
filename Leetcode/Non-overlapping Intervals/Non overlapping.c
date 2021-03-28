//C program for non overlapping intervals

int cmpfunc(int** a, int** b)
{
    int* pa = (*a);
    int* pb = (*b);
    
    //both are 0 then subtract second element
    if(pa[0]==pb[0]) 
        return pa[1] - pb[1];
        //else subtract first element
    else             
        return pa[0] - pb[0];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervalsSize<=1)    return 0;   
    int count=0,right,left;

    qsort(intervals, intervalsSize, sizeof(int*), cmpfunc);

    right=intervals[0][1];
    left=intervals[0][0];
    for(int i=1;i<intervalsSize;i++)
    {
        //if right>intervals[i][0] then increament count
        if(right>intervals[i][0]&&intervals[i][1]>=right)
        {
            count++;
            //if right>intervals[i][1] then store intervals in right
            if(right>intervals[i][1])
                right=intervals[i][1];
        }
        else if(left<intervals[i][1]&&right>=intervals[i][1])
        {
            count++;

            if(right>intervals[i][1])
                right=intervals[i][1];
                //if left<intervals[i][0] then store intervals in left
            if(left<intervals[i][0])
                left=intervals[i][0];
            
        }
        else 
        {
            if(right<intervals[i][1])
                right=intervals[i][1];
            if(left>intervals[i][0])
                left=intervals[i][0];
            
        }
    }
    //return answer
    return count;
}
