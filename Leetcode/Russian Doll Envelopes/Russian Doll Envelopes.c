// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
// One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the 
// other envelope.
// Return the maximum number of envelopes can you Russian doll (i.e., put one inside the other).



// Function to calculate maximum of two integer
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){

	int size = envelopesSize;
    int temp = 0;  
	if(!size) return 0;
	// sort the envelopes array by width of envelope
     for (int i = 0; i < envelopesSize; i++) {     
        for (int j = i+1; j < envelopesSize; j++) {     
           if(envelopes[i][0] > envelopes[j][0]) {    
               temp = envelopes[i][0];    
               envelopes[i][0] = envelopes[j][0];    
               envelopes[j][0] = temp;    
           }     
        }     
    }    
    int* maxrolls;
    maxrolls = calloc(envelopesSize, sizeof(int) );
    int maxroll = 1;
	maxrolls[0] = 1;
    // Traversing the Envelope
	for(int i = 1; i < size; ++i)
	{
		maxrolls[i] = 1;
		for(int j = i-1; j >= 0; --j)
            // Checking if the envelope can be Russian Dolled
             // allocating an array to record the maximal amount for each envelope
			if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1])
				maxrolls[i] = max(maxrolls[i], maxrolls[j]+1);
       // finding the max of two
		maxroll = max(maxroll, maxrolls[i]);
	}
    // the maximum number of envelopes that can be Russian dolled
	return maxroll;
}
