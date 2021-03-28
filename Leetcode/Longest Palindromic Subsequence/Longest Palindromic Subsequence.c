// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the 
// remaining elements.


#include<stdio.h> 
#include<string.h> 

// A utility function to get max of two integers 
int max (int x, int y) { return (x > y)? x : y; } 

// Returns the length of the longest palindromic subsequence in seq 
int lps(char *seq, int i, int j) 
{ 
// Base Case 1: If there is only 1 character 
if (i == j) 
	return 1; 

// Base Case 2: If there are only 2 characters and both are same 
if (seq[i] == seq[j] && i + 1 == j) 
	return 2; 

// If the first and last characters match 
if (seq[i] == seq[j]) 
	return lps (seq, i+1, j-1) + 2; 

// If the first and last characters do not match 
return max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
} 

/* Driver program to test above functions */
int main() 
{ 
    printf("Enter the string: ");
    scanf("%s", str);
	char seq[] = str; 
	int n = strlen(seq); 
	printf ("The length of the LPS is %d", lps(seq, 0, n-1)); 
	getchar(); 
	return 0; 
} 
