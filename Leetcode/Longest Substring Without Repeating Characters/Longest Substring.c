#include <stdbool.h>

int lengthOfLongestSubstring(char * s){
    bool collision_tbl[128] = {0};
    int len = strlen(s);

    if (len <= 1) {
        return len;
    }

    // windows is [lw, rw], so the window length is always rw-lw+1
    // rw can be as high as n
    int lw =0;        // left window
    int rw = 0;       // right window
    int mwl = rw-lw+1;        // max window length
    collision_tbl[s[0]] = true;

    for (int rw=1; rw<len; rw++) {
        if (collision_tbl[s[rw]]) {
            // collision happens
            for (lw; lw < rw; lw++) {
                if (s[lw] == s[rw]) {
                    lw++;  // move left window up 1 to maintain a correct left window
                    // do not need del s[lw], otherwise we will need to add it again
                    break;
                } else {
                    collision_tbl[s[lw]] = false;                   
                }
            }
        } else {
            collision_tbl[s[rw]] = true;
            // find a new window
            if (mwl < rw-lw+1) {
                mwl = rw-lw+1;
            }
        }
    }
 
    return mwl;
}