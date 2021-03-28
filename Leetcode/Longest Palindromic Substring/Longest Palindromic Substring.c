//Problem:https://leetcode.com/problems/longest-palindromic-substring/

/* 
Approach: Expand around the center for even and odd sized palindromes.
# odd sized palindromes willl have one center
#even sized palindromes will have two centers
#from start to end of string, traverse through each index and assume that index as center and expand around this center and also note down the max size as well. 
#repeate the above step assuming each index as center.
*/
int expandAroundCenter(char *s, int x,int y)
{
    if(s==NULL || x>y) return 0;
    while(x>=0 && y<strlen(s) && s[x]==s[y])
    {
        x--; y++;
    }
    return (y-x-1);
}

char * longestPalindrome(char * s){
    int start=0,end=0;
    int ret1,ret2,ret,i=0;
    if(s==NULL || strlen(s)<1) return "";
    
    while(s[i])
    {
        ret1=expandAroundCenter(s,i,i);
        ret2=expandAroundCenter(s,i,i+1);
        ret=ret1>ret2? ret1:ret2;
        if(ret > end - start)
        {
            start=i-(ret-1)/2;
            end=i+ret/2 ;
        }
        i++;
    }
    s[end+1]='\0';
    return &s[start];
}
