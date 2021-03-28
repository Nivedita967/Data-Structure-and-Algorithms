// Alice and Bob take turns playing a game, with Alice starting first.
// Initially, there are n stones in a pile.  On each player's turn, that player makes a move consisting of
//  removing any non-zero square number of stones in the pile.
// Also, if a player cannot make a move, he/she loses the game.
// Given a positive integer n. Return True if and only if Alice wins the game otherwise return False, assuming both players play optimally.


class Solution {
    public boolean winnerSquareGame(int n) {
        // Create an empty hashmap
        HashMap<Integer, Boolean> cache = new HashMap<>();
        // put false at key 0
        cache.put(0, false);
        // Depth First Search Function
        return dfs(cache, n);
    }

    public static boolean dfs(HashMap<Integer, Boolean> cache, int remain) {
        // If the map contains tha key 'remain'
        if (cache.containsKey(remain)) {
            return cache.get(remain);
        }
        
        int sqrt_root = (int) Math.sqrt(remain);
        for (int i = 1; i <= sqrt_root; i++) {
            // if there is any chance to make the opponent lose the game in the next round,
            // then the current player will win.
            if (!dfs(cache, remain - i * i)) {
                cache.put(remain, true);
                return true;
            }
        }
        cache.put(remain, false);
        return false;
    }
}