class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        int rows = matrix.size();
        if (rows == 0)
            return 0;
        int cols = matrix[0].size();
        
        vector <vector<int>> dp(rows, vector<int> (cols, 0));
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (dp[i][j] == 0){
                    dfs(matrix, dp, i, j, INT_MIN);
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
    
    int dfs(vector<vector<int>> &matrix, vector <vector<int>> &dp, int row, int col, int prev){
        if (row < 0 || row>=matrix.size() || col < 0 || col >= matrix[0].size()
                || matrix[row][col] <= prev){
            return 0;
        }
        
        if (dp[row][col] != 0)
            return dp[row][col];
        
        int left = dfs(matrix, dp, row, col-1, matrix[row][col]);
        int rght = dfs(matrix, dp, row, col+1, matrix[row][col]);
        int uppp = dfs(matrix, dp, row-1, col, matrix[row][col]);
        int down = dfs(matrix, dp, row+1, col, matrix[row][col]);
        
        dp[row][col] = max(left, max(rght, max(uppp, down))) + 1;
        
        return dp[row][col];
    }
};
