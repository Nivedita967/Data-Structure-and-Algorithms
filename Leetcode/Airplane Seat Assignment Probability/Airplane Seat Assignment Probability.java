class Solution {
    public double nthPersonGetsNthSeat(int n) {
        if(n==1){
            //If there is only one seat, then the answer will be 1
            return 1.00000;
        }
        else{
            //There are 3 cases
            //Case 1: First person sits on seat 1. In this case all the other people from 2 to n-1 will get the correct seat and person n will get nth seat
            //Case 2: First person sits on seat n. In this case all the other people from 2 to n-1 will again get the correct seat but person n will end up in seat 1
            //Case 3: First person sits on seat anywhere from 2 to n-1. In this case, this will displace someone from their original seat and until reaching person n-1, either seat 1 or seat n will be already occupied. 
            //One thing to observe is that the person n either ends up on first seat or nth seat, depending on which of them is occupied first by other n-1 people. So in order for nth person to sit on nth seat, there is a probabilty of 1/2 (because chance of nth seat being empty against both seats 1 and n). And thus for any n>=2, it will remain the same
            return 0.50000;
        }
    }
}
