/*
    Time Complexity: O(N*M)
    Space Complexity: O(N*M)

    where 'N' and 'M' denote the number of rows and columns.
*/


vector<int> dirX = {0, 0, 1, -1};
vector<int> dirY = {1, -1, 0, 0};


bool isValid(vector<vector<int>> &mat, int x, int y, int dx, int dy)
{
    int n = mat.size();
    int m = mat[0].size();

    /*
     Check boundary conditions and if the next element 
     is a greater element
    */
    if (dx >= 0 && dx < n && dy >= 0 && dy < m && mat[dx][dy] > mat[x][y])
    {
        return true;
    }

    return false;
}


int dfs(vector<vector<int>> &mat, vector<vector<int>> &dp, int x, int y)
{
    // If the path has already been searched, return 
    if (dp[x][y] != 0)
    {
        return dp[x][y];
    }

    // A single element forms an increasing path of length 1
    int len = 1;

    // Check along the 4 directions one by one
    for (int i = 0; i < 4; i++)
    {
        int dx = x + dirX[i];
        int dy = y + dirY[i];

        if (isValid(mat, x, y, dx, dy))
        {
            int currLen = dfs(mat, dp, dx, dy) + 1;
            len = max(currLen, len);
        }
    }

    dp[x][y] = len;

    return len;
}


int longestIncreasingPath(vector<vector<int> > &mat, int n, int m)
{
    int maxLen = 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Find longest increasing path starting from each cell
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxLen = max(dfs(mat, dp, i, j), maxLen);
        }
    }

    return maxLen;
}
