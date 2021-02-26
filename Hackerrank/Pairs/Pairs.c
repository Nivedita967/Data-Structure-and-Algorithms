//TODO: Determine the number of pairs of array elements that have a difference equal to the target value.

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the pairs function below.
int pairs(int k, int arr_count, int* arr) {                        //TODO: Function for counting required pairs
    int count = 0;
for (int i = 0; i < arr_count; i++)
{
    for(int j = 0; j< arr_count;j++)
    {
        if(arr[i]-arr[j]==k)
        {
            count++;
        }
    }
}
return count;

}
 // These whole functions mentioned below will be provided by hackerrank itself
int main()                                                                       
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nk = split_string(readline());

    char* n_endptr;
    char* n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char** arr_temp = split_string(readline());

    int* arr = malloc(n * sizeof(int));                                     //TODO: Allocating space for the array

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = n;

    int result = pairs(k, arr_count, arr);

    fprintf(fptr, "%d\n", result);                                               //TODO: Printing result

    fclose(fptr);                                                                //TODO: Closing created file

    return 0;
}

char* readline() {                                                                //TODO: Read lines
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {                                                   //TODO: Calculating splits
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;                                      //TODO: Returning number of spaces
}
