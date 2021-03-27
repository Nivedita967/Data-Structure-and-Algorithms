
//C program to set matrix zero
// node is created
typedef struct node{
    int x;
    int y;
    struct node* next;
}node;

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    //two node variables are used
    node *tmp;
    node *head = NULL;

    int first=1;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<*matrixColSize;j++)
        {
            //if matrix element is zero then store it in form of linked list
            if(matrix[i][j]==0)
            {
                    node *N = malloc(sizeof(struct node));
                    N->x = i;
                    N->y = j;

                    //if it is not first element
                    //then temp->next is N
                    if(!first)
                    {
                        tmp->next = N;
                        tmp = tmp -> next;  
                    }
                    //if it is first element
                    //then temp is N
                    else 
                    {
                        tmp = N;
                        head = N;
                        first = 0;
                    }
            }
        }
    }
    
    tmp -> next = NULL;
    
    while(head)
    {
        int i;
        //run the loop till matrixColsize
        for(i=0;i<*matrixColSize;i++)
            matrix[head->x][i] = 0;
        //run the loop till matrixSize
        for(i=0;i<matrixSize;i++)
            matrix[i][head->y] = 0;
        
        head = head->next;
    }
}

