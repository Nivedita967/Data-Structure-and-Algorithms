//DFS with memoization

//Use global pointer to access the memory array. 
const char *s_start, *p_start; 
char **cache; 

bool Match (const char *s, const char *p) {
    //load memory if available
    if (cache[s - s_start][p - p_start] >= 0)  return cache[s-s_start][p-p_start]; 

    if (*p == '\0')
        return cache[s-s_start][p-p_start] = '\0' == *s;
    if (*p == *s || (*p == '?' && *s))
        return cache[s-s_start][p-p_start] = Match(s + 1, p + 1);
    if (*p == '*') {
        while (*p == '*') p++; //skip continuous '*'
        if (*p == '\0') return true;
        for (;*s;s++)
            if (Match (s, p))
                return cache[s-s_start][p-p_start] = true;
        return false;
    }
    return false;
}

bool isMatch(char* s, char* p) {
    int s_n=strlen(s), p_n=strlen(p);
    
    //use local array to do dynamic array without malloc/free
    char Cache[s_n+1][p_n+1]; 
    memset(Cache, -1, sizeof(Cache));
    
    //Use global pointer to access the memory array. 
    char *ptr[s_n+1];
    for (size_t i = 0; i < s_n + 1; i++)
        ptr[i] = Cache[i];
    cache = ptr;
    s_start = s, p_start = p;

    return Match (s_start, p_start);
}