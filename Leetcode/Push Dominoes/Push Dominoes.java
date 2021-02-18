class Solution {
    public String pushDominoes(String dominoes) {
        //Converting string to character array so that we can traverse and process each character individually
        char[] domino_char= dominoes.toCharArray();
        //Calculating size of our array
        int size= domino_char.length;
        //Defining direction array for each character in the string
        int[] direction= new int[size];
        //Defining intital state
        int state=0;
        //Looping through our character array left to right
        for(int i=0;i<size;i++){
            //If we encounter right direction
            if(domino_char[i]=='R'){
                //It has the ability to knock down dominoes till size
                state= size;
            }
            else if(domino_char[i]=='L'){
                //State gets nullified
                state=0;
            }
            else{
                //The state gets changed for each domino as we go thorugh them second by second
                state= Math.max(state-1,0);
            }
            direction[i]+= state;
        }
        // Reinitialising state to 0
        state=0;
        //Now looping through our character array right to left
        //We will traverse in the same way, but this time the sign of direction will be negative
        for(int i=size-1;i>=0;i--){
            //If we encounter left direction
            if(domino_char[i]=='L'){
                state= size;
            }
            else if(domino_char[i]=='R'){
                //State gets nullified
                state=0;
            }
            else{
                //The state gets changed for each domino as we go thorugh them second by second
                state= Math.max(state-1,0);
            }
            direction[i]-= state;
        }
        
        //Creating our answer string
        StringBuilder ans= new StringBuilder();
        
        for(Integer i: direction){
            //If we have positive direction
            if(i>0){
                ans.append('R');
            }
            //If we have negative direction
            else if(i<0){
                ans.append('L');
            }
            //If we have equilibrium
            else{
                ans.append('.');
            }
        }
        return ans.toString();
    }
}
