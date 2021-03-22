class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> temp(n, 0);
        for (int i=0;i<edges.size();i++){
            temp[edges[i][1]]++; //calculate the indegree
        }
        vector<int>ans;
        for (int i=0;i<n;i++){
            if (temp[i]==0){ // if any node has zero indegree it has to be included, rest can be reached from the other nodes.
                ans.push_back(i);
            }
        }
        return ans;
    }
};