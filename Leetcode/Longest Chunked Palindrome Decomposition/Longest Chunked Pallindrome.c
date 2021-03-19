
// C Program to find Longest Chunked Palindrome Decomposition using recursion
int longestDecomposition(char * text) {
    char *s = text; char *ep = s + strlen(s) - 1;
    if (!strlen(s)) return 0;     
    
    /* Match substrings at the beginning and end */
    int i = 1;
    while (strncmp(s, ep, i)) { ep--; i++; if (ep <= s) break; }
    
    if (ep <= s) return 1;     /* Only one unique substring - return 1 */
    s += strlen(ep); *ep = 0;  /* Take out substrings matched */
    
    return 2 /* found */ + longestDecomposition(s); /* recurse to find more in the shortened string */
}

