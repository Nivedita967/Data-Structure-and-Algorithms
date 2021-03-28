class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnts; // frequency count table
    // cumulative frequency count table, 
    // i.e., table[i] means the number of numbers whose frequency is no less than i
    vector<int> cumulativeFrequencyTable(nums.size()+1, 0);
    for (auto &i : nums) {
        ++cumulativeFrequencyTable[++cnts[i]];
    }
    
    // find the largest mininum frequency Fmin so that the number of numbers with frequency larger than Fmin >= k.
    int minFrequency = nums.size();
    for (; minFrequency>0 && cumulativeFrequencyTable[minFrequency]<k; --minFrequency);
    
    // construct the final result
    vector<int> result(k);
    int cnt = 0;
    // first insert those numbers with frequency large than Fmin.
    for (auto &aPair : cnts) {
        if (aPair.second > minFrequency && cnt < k) {
            result[cnt++] = aPair.first;
        }
    }
    
    // in case numbers not enough, insert some numbers with frequency equals to Fmin.
    for (auto &aPair : cnts) {
        if (aPair.second == minFrequency && cnt < k) {
            result[cnt++] = aPair.first;
        }
    }
    
    return result;
}
};