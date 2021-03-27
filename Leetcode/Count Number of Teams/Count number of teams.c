
//C Program to count number of teams
int numTeams(int* rating, int ratingSize){
    int *rem;
    int ans=0;
    //allocating size for rem
    rem = calloc(sizeof(int),ratingSize);
    rem[0] = 0;
    
    //forward
    for(int i=1; i<ratingSize; i++) {
        
        for(int j=0; j < i; j++) {
            //checking the condition
            if(rating[i] > rating[j]) {
                rem[i]++;
                ans += rem[j];
            }        
        }
    }
    
    rem[ratingSize-1] = 0;
        //backward   
    for(int i=ratingSize-2; i>=0; i--) {
        rem[i] = 0;
        for(int j = ratingSize-1; j > i; j--) {
            //checking the condition
            if(rating[i] > rating[j]) {
                rem[i]++;
                ans += rem[j];
                
            } 
        }
        
    }
     //return the answer
    return ans;
}

