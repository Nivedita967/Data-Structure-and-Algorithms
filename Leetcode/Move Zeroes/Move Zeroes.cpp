class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//         Intializing Numsize();
       int n = nums.size();
        int k = 0;
        // .erase function is an inbuild funcion used in c++ to erase a particular element in a vector
       for (auto i = nums.begin(); i != nums.end(); ++i) {
        if (*i == 0) {
            k++;
            nums.erase(i);
            i--;
        }
       }
//         In this step we are inserting zeroes at the back of the vector and finally cout it
        for(int i = 0 ; i < k ; i++)
        {
        auto it = nums.insert(nums.end() , 0);
        }
        for (auto it = nums.begin(); it != nums.end(); ++it) 
        cout << *it << " "; 
       }
};