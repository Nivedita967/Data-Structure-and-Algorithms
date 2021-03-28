class Solution {
public:
    // Finds the substring with atmost K unique chars
    int atmostK(vector<int>& arr, int K) {
        int i = 0, j = 0, substrings = 0;
        unordered_map<int, int> freq;
        const int N = arr.size();
        
        while(i < N) {
            // Expand the window
            if(K >= 0) {
                ++freq[arr[i]];
                if(freq[arr[i]] == 1)
                    --K;
                ++i;
            }
            // make the window valid
            while(K < 0) {
                --freq[arr[j]];
                if(freq[arr[j]] == 0)
                    ++K;
                ++j;
            }
            // Each valid window adds the subarrays which satisfies the condition
            // For : 1,2,1, k=2
            // 1: [1] 
            // 2: [2], [1,2]
            // 3: [1,2], [2,1], [1,2,1]
            substrings += i - j + 1;
        }
        return substrings;
    }
    
    int subarraysWithKDistinct(vector<int>& arr, int K) {
        return atmostK(arr, K) - atmostK(arr, K-1);
    }
};