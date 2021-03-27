import java.util.*;
public int minSwapsCouples(int[] a) {
    int n = a.length, count=0;
    int[] revIndex = new int[n];
    // fix 1 couple at a time. Fixing 1 couple means check where his partner is and bring her next to him
    for(int i=0; i < n; i++)
    // We need to do this process for i=0,2,4,..., so we need a revIndex.
        revIndex[a[i]] = i;
    for(int i=0; i < n; i+=2){
        // if a[i] is even, partner is a[i]+1 else partner is a[i]-1
        int partner = a[i] % 2 == 0 ? a[i]+1 : a[i]-1;
        // Swap partners and their positions at a time.
        if(a[i+1] != partner){
            ++count;
            //fix partner position
            int tmp = a[i+1], j = revIndex[partner];
            a[i+1] = a[j];
            a[j] = tmp;
            //fix revIndex
            int tmp2 = revIndex[tmp];
            revIndex[tmp] = revIndex[partner];
            revIndex[partner] = tmp2;
        }            
    }
    return count;
}