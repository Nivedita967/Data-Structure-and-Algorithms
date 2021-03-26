int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelf_width){
   int D[booksSize];
    int len = booksSize -1; 
    // D array will contain answer for each book
    D[0] = books[0][1];
    // Iterating through the books
    for(int i = 1; i <= len; i++)
    {
        // Finding the width & Height 
        int width = books[i][0];
        int height = books[i][1];
        //Assigning D value to moving it to new shelf, i.e. adding height
        D[i] = D[i-1] + height;
        int size = i-1;
        int newWidth = width;
        int newHeight = height;
        //Finding min value of d where we can either move each book to new level or add the current book to new shelf
        while(size >= 0)
        {
            newWidth += books[size][0];
            if(newWidth<=shelf_width)
            {
                newHeight = fmax(newHeight , books[size][1]);
                if(size >0 )
                {
                    //Finding min value of d where we can either move each book to new level or add the current book to new shelf
                    D[i] = fmin(D[i], newHeight+D[size-1]); 
                }

            }
            else
            {
                break;
            }
            size--;
        }
        if(size>=0)
        {
            newHeight += D[size];                

        }
        D[i] = fmin(D[i], newHeight);
    }
    //Returning required answer
    return D[len];
}