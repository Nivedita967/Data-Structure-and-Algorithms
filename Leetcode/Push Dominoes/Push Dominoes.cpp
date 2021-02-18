class Solution {
public:
    string pushDominoes(string dominoes) {
        //Calculating size of our string
        int size= dominoes.length();
        //Defining direction vector for each character in the string
        vector<int> direction(size);
        //Defining intital state
        int state=0;
        //Looping through our string from left to right
        for(int i=0;i<size;i++){
            //If we encounter right direction
            if(dominoes[i]=='R'){
                //It has the ability to knock down dominoes till size
                state= size;
            }
            else if(dominoes[i]=='L'){
                //State gets nullified
                state=0;
            }
            else{
                //The state gets changed for each domino as we go thorugh them second by second
                state= max(state-1,0);
            }
            direction[i]+= state;
        }
        // Reinitialising state to 0
        state=0;
        //Now looping through our string from right to left
        //We will traverse in the same way, but this time the sign of direction will be negative
        for(int i=size-1;i>=0;i--){
            //If we encounter left direction
            if(dominoes[i]=='L'){
                state= size;
            }
            else if(dominoes[i]=='R'){
                //State gets nullified
                state=0;
            }
            else{
                //The state gets changed for each domino as we go thorugh them second by second
                state= max(state-1,0);
            }
            direction[i]-= state;
        }
        
        //Creating our answer string
        string ans="";
        
        for(auto i: direction){
            //If we have positive direction
            if(i>0){
                ans+= 'R';
            }
            //If we have negative direction
            else if(i<0){
                ans+= 'L';
            }
            //If we have equilibrium
            else{
                ans+= '.';
            }
        }
        return ans;
    }
};
