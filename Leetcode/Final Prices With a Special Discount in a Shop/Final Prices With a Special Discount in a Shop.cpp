class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> res(prices.size());
		//start traversing from right
        st.push(prices[prices.size()-1]);
        res[prices.size()-1] = prices[prices.size()-1];
        for(int i = prices.size()-2; i >= 0; i--)
        {
            int x = st.top(); //discount
			//discount cannot be greater than the current item's price
            while(x>prices[i])
            {
                st.pop();
                if(st.empty())
                {
                    x = 0; //there is no discount available on current item
                    break;
                }
                x = st.top();
            }
        
            res[i] = (prices[i] - x); 
            st.push(prices[i]); // push current element into stack
        }
        return res;
    }
};