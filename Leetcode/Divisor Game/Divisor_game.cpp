// * ALGORITHM => 
// * This question is from Game Theory.
// * We have to think this question logically and if the players play this game optimally.
// * The logical deduction is that if the number is even, then Alice can use 1 to divide any N and subract it from leaving N as odd which will make Bob loose.
// * If the number which was given is odd, then Alice will loose by the same logical pattern as stated by above point.

class Solution{
public:
    bool divisorGame(int N){
        if (N % 2 == 0){
            return true;
        }
        else{
            return false;
        }
    }
};