class Solution {
    public int numDecodings(String str) {

        //dp array of length equals to string
        int[]dp= new int[str.length()];

        //Initialised with 0
        Arrays.fill(dp, 0);
    
        for(int i=0;i<str.length();i++){

            //if string starts with 0th character
            if(i==0){
                if(str.charAt(i)=='0'){
                    continue;
                }
                else{
                    dp[0]=1;
                }
            }

            //other characters of string
            else{

                //if string is 0 non 0
                if(str.charAt(i)=='0' && str.charAt(i-1)!='0'){
                    if(str.charAt(i-1)=='1' || str.charAt(i-1)=='2'){
                        if(i<2){
                            dp[i]=1;
                        }
                        else
                            dp[i]=dp[i-2];
                    }
                }

                //if string is 0 0
                else if(str.charAt(i)=='0' && str.charAt(i-1)=='0'){
                    continue;
                }

                //if string is non 0 0
                else if(str.charAt(i)!='0' && str.charAt(i-1)=='0'){
                    dp[i]=dp[i-1];
                }

                //if string is non zero non zero
                else{
                    String temp = str.substring(i-1, i+1);
                    int num = (str.charAt(i-1)-'0')*10 + (str.charAt(i)-'0');
                    dp[i]=dp[i-1];
                    if(num<=26){
                        if(i<2){
                            dp[i]+=1;
                        }
                        else
                            dp[i]+=dp[i-2];
                    }
                }
            }
        }
        //returning the no of possible encodings
    return dp[str.length()-1];
    }
}