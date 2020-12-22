/*
 * https://leetcode.com/problems/minimum-path-sum/submissions/
 * Min path from (0,0) to (n,n)
 */

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    if (row == 0 || col == 0)
        return 0;

    int minDP[row][col];
    memset(minDP, 0, sizeof(minDP));

    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (i==0 && j==0){
                minDP[i][j] = grid[i][j];
                continue;
            }
            if (i==0){
                minDP[i][j] = grid[i][j] + minDP[i][j-1];
                continue;
            }
            if (j==0){
                minDP[i][j] = grid[i][j] + minDP[i-1][j];
                continue;
            }
            minDP[i][j] = min(minDP[i][j-1], minDP[i-1][j]) + grid[i][j];
        }
    }
    return minDP[row-1][col-1];
}
