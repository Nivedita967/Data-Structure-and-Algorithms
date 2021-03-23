class Solution {
public:
    int algo(int l,int h,vector<int>& nums){
        if (l==h) return l;  //If the both the high and low indexes are equal i.e length of array is 1, return that number.
        int m= (l+h)/2;  //Calculate the middle element index of the array.
        int a=algo(l,m,nums);  //Recursively search in first half
        int b=algo(m+1,h,nums); //Recursively search in the next half
        //cout<<a<<b<<endl;
        if (nums[a]>=nums[b]) return a;
        return b;
    }
    
    int findPeakElement(vector<int>& nums) {
        return algo(0,nums.size()-1,nums);
    }
};