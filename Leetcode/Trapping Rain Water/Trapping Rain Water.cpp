class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int n=height.size();
        
        vector<int>maxL(n),maxR(n);
        
        maxL[0]=height[0];
        for(int i=1;i<n;i++)
            maxL[i]=max(maxL[i-1],height[i]);
        
        maxR[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            maxR[i]=max(maxR[i+1],height[i]);
        
        long long int ans=0;
        
        vector<int>water(n);
        for(int i=0;i<n;i++)
        {
            water[i]=min(maxL[i],maxR[i])-height[i];
            ans+=water[i];
        }
        
        return ans;
    }
};