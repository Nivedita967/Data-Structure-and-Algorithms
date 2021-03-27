// This is the most optimized code for the following question, Time complexity for the code is O(1).
class Solution {
public:
    bool divisorGame(int N) {
        // This states that whenever the Value of N is even then it returns true else false
        return N%2==0;
    }
};
// Logic behind :-
// Basically since Alice will start playing so she will won at n=2 for sure,
//  then she will be  definitely wining at n=4 and 
// so on at all even no.s this thing happen. Similarly for odd no.s they are losing it.