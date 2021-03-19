#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) 
    {
        //declaration of map
         vector<int> maps;
        
        //loop for taking string words into map
        for(int i = 0; i<words.size();i++)
        {
            string word = words[i];
            sort(word.begin(),word.end());
            maps.push_back(count(word.begin(),word.end(),word[0])); 
        }
        
        //sorting map
        sort(maps.begin(),maps.end());
        
        //vector declaration
        vector<int> ans;
        
        //loop to compare strings
        for(int i = 0;i<queries.size();i++)
        {
            string word = queries[i];
            sort(word.begin(),word.end());
            int count_ = count(word.begin(),word.end(),word[0]);
            int upper1 = upper_bound(maps.begin(), maps.end(), count_) - maps.begin(); 
            
            //taking the counted number of words according to the question
            ans.push_back(maps.size()-upper1);
        }
        
        //returning vector
        return ans;
    }
};