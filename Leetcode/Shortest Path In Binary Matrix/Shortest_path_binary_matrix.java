class Solution {
    public:
        int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.length;
        int[][] distance = new int[n][n];
        for (int[] dist: distance) {
            Arrays.fill(dist, -1);
        }
        distance[0][0] = 1;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        queue.add(0);

        while (queue.size() > 0) {
            int row = queue.poll();
            int col = queue.poll();

            int[] rowMoves = {1, -1, 0, 0, 1, -1, -1, 1};
            int[] colMoves = {0, 0, -1, 1, -1, 1, -1, 1};

            for (int i = 0; i < 8; i++) {
                int newRow = row + rowMoves[i];
                int newCol = col + colMoves[i];

                if (newRow >= 0 && newRow < n && newCol >=0 && newCol < n && distance[newRow][newCol] == -1 && grid[newRow][newCol] == 0) {
                    distance[newRow][newCol] = distance[row][col] + 1;
                    queue.add(newRow);
                    queue.add(newCol);
                }
            }
        }
        System.out.println(Arrays.deepToString(distance));
        return distance[n - 1][n - 1];
    }
}