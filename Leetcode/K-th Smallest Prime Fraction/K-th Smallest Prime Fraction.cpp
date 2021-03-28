typedef pair<double,pair<int,int>> ps;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         We Have Created Min Priority Queue Here And All the Values There Will Be Stored As Pair 
        priority_queue<ps,vector<ps>,greater<ps>> pq;
        for(int i=0;i<arr.size();++i)
            for(int j=i+1;j<arr.size();++j)
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            
        while(--k)
            pq.pop();
//         Returning Vector Here
        return vector<int>{pq.top().second.first,pq.top().second.second};
    }
};