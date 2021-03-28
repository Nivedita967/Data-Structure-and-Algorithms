//C program for Minimum Add to Make Parentheses Valid

int minAddToMakeValid(char * S){
    //find length
int len = strlen(S);
    int miss_par = 0;
    int c = 0;  
    for (int i = 0; i < len; ++i) {
        //checking for parantheses
        *(S+i) == '(' ? c++ : c--;
        c < 0 ? (miss_par++, c++) : 1;
    }
    //storing in miss_par
    miss_par += c;
    //return answer
    return miss_par;
}

