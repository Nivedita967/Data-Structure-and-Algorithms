//TODO: Find the length of the longest valid parentheses substring of a given string


int longestValidParentheses(char * s){ 
  
   int cap = 8000, error = -1;
    int length = 0, max_length = 0;
    char *p = s;
    int *pstack = malloc(cap * sizeof(int));                            //TODO: Allocating space for pstack
    int *top = pstack;

    while (*p != '\0') {
        if (*p == '(') {                                                //TODO: Validating Parentheses
            if (top + 1 - pstack >= cap) {
                cap *= 2;
                pstack = realloc(pstack, cap * sizeof(int));            //TODO: Allocating space for pstack
            }
            *top++ = p - s;
        } else {
            if (top > pstack) {
                if (--top == pstack) {
                     length = p - (s + error);
                } else {
                    length = p - (s + *(top - 1));
                }
                if (length > max_length) {                             //TODO: Updating maximum length
                    max_length = length;
                }
            } else {
                error = p - s;
            }
        }
        p++;
    }
    return max_length;                                                   //TODO: Returning result
}
