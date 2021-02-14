int jumpingOnClouds(int c_count, int* c) 
{
    int count =0;
    for(int i=0; i<c_count-1; i++) //No need to check for the last jump as there will be no zeroes if last term is 1
    {
        if(c[i]==0)
        {
            if(c[i+2]==0) //First checking for higher jump if possible skip one i
            {
                count++;
                i++;
            }
            else
            {
                count++;
            }
        }
    }
    return count;
}
