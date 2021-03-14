// A Program to Sort given strings in given basis

// Sorting by lexicographic order
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// Sorting by reversed lexicographic order
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Calculating and sorting by number of distinct characters
#define CHARS   26
int distinct_chars(const char *a)
{
    int dist = 0;
    int chars[CHARS] = {0};

    while (*a != '\0') {
        int chr = (*a++) - 'a';
        if (chr < CHARS)
            chars[chr]++;
    }
    
    for (int i = 0; i < CHARS; i++)
        if (chars[i])
            dist++;

    return dist;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int res = distinct_chars(a) - distinct_chars(b);
    return (res) ? res : lexicographic_sort(a, b);
}


// Sorting by length
int sort_by_length(const char* a, const char* b) {
    int res = strlen(a) - strlen(b);
    return (res) ? res : lexicographic_sort(a, b);
}

void string_sort(char** arr, const int len,int (*cmp_func)(const char* a, const char* b)) {
    int sorted = 0;
    int top = len - 1;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < top; i++) {
            if (cmp_func(arr[i], arr[i + 1]) > 0) {
                char *tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = 0;
            }
        }
        top--;
    }
}

