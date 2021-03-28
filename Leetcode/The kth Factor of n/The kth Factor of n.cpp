class Solution {
public:
    int kthFactor(int n, int k) {
        // array: 1 2 3 4 6 8 12 24
        // index:  0 1 2 3 4 5 6  7
        // suppose k:6, we should return 8
        // we check until sqrt(24) = 4 so array will be 1 2 3 4 (array.size()==4)
        // we find the answer(8) by dividing n by array[array.size() - k]==array[2]==3
        // note that if k>array.size() than we should return -1
        vector<int>array;
        int i;
        for(i=1;i*i<=n;i++){
            if(n%i==0){
                if(i*i!=n){array.push_back(i);}
                if(--k==0){return i;}
            }
        }
        return (k>array.size())? -1 : n/(array[array.size()-k]);
    }
};