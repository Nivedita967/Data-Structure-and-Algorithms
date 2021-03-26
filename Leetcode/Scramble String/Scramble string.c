
//C program for scramble string
bool isScramble(char * s1, char * s2){

// length of s1
int len = strlen(s1);
//checking the length
    if(!len) return true;
    if(len==1) return *s1==*s2;
    //creating a new variable match
    bool*** match = (bool***)malloc(sizeof(bool**)*(len+1));
    for(int i = 0; i <= len; i++)
    { 
        //initializing match[i]
        match[i] = (bool**)malloc(sizeof(bool*)*len);
        for(int j = 0; j < len; j++)
        {
            //initializing match[i][j]
            match[i][j] = (bool*)malloc(sizeof(bool)*len);
            memset(match[i][j], 0, sizeof(bool)*len);
        }
    }
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
        //running a loop and storing the value in match
            match[1][i][j] = (s1[i] == s2[j]);
    for(int size = 2; size <= len; size++)
        for(int i = 0; i <= len-size; i++)
            for(int j = 0; j <= len-size; j++)
                for(int k = 1; k<size && !match[size][i][j]; k++)
                
                    match[size][i][j] = (match[k][i][j] && match[size-k][i+k][j+k]) || (match[k][i+size-k][j] && match[size-k][i][j+k]);
    //return the result
    return match[len][0][0];
}


