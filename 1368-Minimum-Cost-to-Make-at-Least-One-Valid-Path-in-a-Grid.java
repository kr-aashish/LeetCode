// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int[][] cost = new int[m][n];

        for (int[] row : cost) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.offer(new int[]{0, 0, 0});
        cost[0][0] = 0;

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int x = current[0], y = current[1], currCost = current[2];

            if (x == m - 1 && y == n - 1) {
                return currCost;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];

                // just learn this cost calculation logic
                int newCost = currCost + (grid[x][y] == i + 1 ? 0 : 1);

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    pq.offer(new int[]{nx, ny, newCost});
                }
            }
        }

        return -1;
    }
}