class Solution {
    public static final int MOD = (int) (1e9 + 7);
    Map<Character,Integer> vowmap;
    public int countVowelPermutation(int n) {
        if (n == 1)
            return 5;
        /***
        vowmap = new HashMap<>();
        vowmap.put('a',0);
        vowmap.put('e',1);
        vowmap.put('i',2);
        vowmap.put('o',3);
        vowmap.put('u',4);
       
        ***/
        // cnt keeps track of number of strings ending in that char
        int[][] cnt = new int[n][5];
        for(int i = 0; i < 5; i++){
            cnt[0][i] = 1;
        }
        // translate hte rules into the patterns possible
        // ae , ea ei, ia, ie, io, iu, oi, ou, ua
        // and once you the list of possible patterns
        // to end in a which patterns are possible like ea, ia, ua
        // so use i-1 of those pre letters to get this i's a count (ending)
        for(int i = 1; i < n; i++){
            //a may come after u or e -- ea , ia, ua
            cnt[i][0] = (cnt[i-1][1] + cnt[i-1][4]) % MOD;
            // a following i is ok (i may not be followed by i)
            cnt[i][0] = (cnt[i][0] + cnt[i-1][2]) % MOD ;
            
            // a may be only followed by e --- ae ie
            cnt[i][1] = (cnt[i-1][0] + cnt[i-1][2]) % MOD;
            
            // ei, oi
            // i -- may not be followed by i and e may be followed by i or a, o may be follow by i
            cnt[i][2] = (cnt[i-1][1] + cnt[i-1][3] ) % MOD;
            
            // o - ending in o --- io,  
            cnt[i][3] = cnt[i-1][2];
            
            // u - iu, ou   
            cnt[i][4] = (cnt[i-1][2] + cnt[i-1][3]) % MOD;
        }
        
        int rslt = 0;
        for(int i = 0; i < 5; i++){
            rslt = (rslt + cnt[n-1][i]) % MOD;
        }
        return rslt;
    }
}