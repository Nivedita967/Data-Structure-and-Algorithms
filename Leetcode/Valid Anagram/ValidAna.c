bool isAnagram(char * s, char * t)
{
    /*
    for each string we will count occurence of 
    the particular character
    */
    char a1[26], a2[26]; 
    for(int i=0; i<26; i++) //Making 0 to avoid garbage value
    {
        a1[i]=0;
        a2[i]=0;
    }
    for(int i=0; s[i]!='\0'; i++) //counting string s
    {
        int j = s[i] - 97;
        
        a1[j]++;

    }
    for(int i=0; t[i]!='\0'; i++) //counting string t
    {
        int k = t[i] - 97;
        a2[k]++;  
    }
    for(int i=0; i<26;i++)
    {
        if(a1[i]!=a2[i]) //If any of the occurence mismatch return false
            return false;
    }
    return true;
}
