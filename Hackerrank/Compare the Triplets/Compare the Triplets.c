int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {

  int i, aliceCounter = 0, bobCounter = 0;  //initialize variables

  *result_count = 2;
  static int res[2]; 

   
  for (i = 0; i < a_count; i++)  //iterate through the array
 {  
     if(a[i] > b[i]) //compare the values
        {
            aliceCounter++;
        }
    else if(a[i] < b[i])
        {
            bobCounter++;
        }
        else
        {
            continue;
        }
 }
    
    res[0] = aliceCounter;  //assign the respective values
    res[1] = bobCounter;
    
    return res;  return back the array
}

