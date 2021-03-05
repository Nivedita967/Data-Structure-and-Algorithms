class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int a=0;
        int j=0;
        vector <double> res;
        multiset <long long int, greater <int>> temp;
        multiset <long long int, greater <int> > :: iterator itr;
        for (int i=0;i<nums.size();i++){
            temp.insert(nums[i]);
            j++;
            if (j==k){
                itr=temp.begin();
                advance(itr, temp.size() / 2);

                if(k%2 == 0) {
                    res.push_back((*itr + *(--itr))/2.0);
                }else {
                    res.push_back(*itr);
                }
                temp.erase(temp.find(nums[a]));
                a++;
                j=k-1;
            }
        }
        return res;
    }
};