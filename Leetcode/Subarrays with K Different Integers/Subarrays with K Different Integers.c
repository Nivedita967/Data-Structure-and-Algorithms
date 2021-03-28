int subarraysWithKDistinct(int* A, int ASize, int K){

int * m;
// m is our window
m = calloc(ASize + 1, sizeof(int) );
int res = 0;
// iterate through the array and use two pointers for our sliding window ([j, i])
for(auto i = 0, j = 0, prefix = 0, cnt = 0; i < ASize; ++i) {
    // we keep tabs on how many times each number appears in our window (m)
    if (m[A[i]]++ == 0) ++cnt;
    // If the subarray [j, i] contains K unique numbers, and first prefix numbers also appear in [j + prefix, i] subarray,
    //  we have total 1 + prefix good subarrays. 
    if (cnt > K) --m[A[j++]], --cnt, prefix = 0;
    // we add next number to the back of our window, we try to remove as many as possible numbers from the front, 
    // until the number in the front appears only once. While removing numbers, we are increasing prefix.
    while (m[A[j]] > 1) ++prefix, --m[A[j++]];
    // If we collected K unique numbers, then we found 1 + prefix sequences
    if (cnt == K) res += prefix + 1;
  }
  return res;
}