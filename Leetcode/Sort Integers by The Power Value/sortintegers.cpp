class Solution {
public:   
    bool static cmp(pair<int, int>& a, 
         pair<int, int>& b) 
    { 
        if (a.second==b.second){
            return a.first<b.first;
        }
        return a.second <= b.second; 
    } 

    // Function to sort the map according 
    // to value in a (key-value) pairs 
    int sortmap(map<int, int>& M,int k) 
    { 

        // Declare vector of pairs 
        vector<pair<int, int> > A; 
        // Copy key-value pair from Map 
        // to vector of pairs 
        for (auto& it : M) {
            A.push_back(it); 
        } 
        
        if (A.empty()) cout<<"hello";

        // Sort using comparator function 
        sort(A.begin(), A.end(), cmp); 
        
        int i=1;
        
        for (auto& it : A){
            if (i==k){
                return it.first;
            }
            i++;
        }
        
        
        return -1;
    }
    int getKth(int lo, int hi, int k) {
        queue<int> wl; 
        map<int,int> res;  //store the calculated values, to avoid recalculation.
        map<int, int>::iterator itr; 
        int temp,count=0;
        for (int i=lo;i<=hi;i++){
            itr = res.find(i);
            if (itr==res.end()){ //if the number is already present no need to calculate again.
                temp=i;
                count=0;
                while(temp!=1){
                    if (temp%2==0){  //If divisible by two, divide the number by 2.
                        temp/=2;
                    }
                    else{
                        temp=3*temp+1;
                    }
                    wl.push(temp);
                    count++;
                }
                res.insert(pair<int, int>(i, count));
                while(!wl.empty()){
                    count--;
                    temp=wl.front();
                    wl.pop();
                    itr = res.find(temp);
                    if (temp>=lo && temp<=hi &&itr==res.end()){
                        res.insert(pair<int,int>(temp,count));
                    }
                }
            }
        }
        
        // cout<<res.find(570)->second;
        // cout<<res.find(573)->second;
        
        return sortmap(res,k);
        
    }
};