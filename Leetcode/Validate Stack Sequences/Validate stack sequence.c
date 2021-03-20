
// C program to validate the stack sequence
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int i = 0, j = 0, k = 0;
    //initialing an array
    int * arr = (int*) malloc (pushedSize * sizeof(int));
    //checking the conditions
	while (k >= 0 && k < pushedSize && j < poppedSize)
	{
		if (k>0 && arr[k-1] == popped[j]) {
			k--; j++;
		}
		else
		{
			if (i < pushedSize)
			{
				if (pushed[i] == popped[j])
				{
					i++; j++;
				}
				else {
					arr[k++] = pushed[i++];
				}
			}
			else 
            {
                free (arr);
				return false;
            }
		}
	}

    //clearing the array and returning true or false
    free (arr);
	return true;
}

