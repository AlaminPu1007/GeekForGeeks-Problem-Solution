#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        // define an visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // define queue data-structure
        queue<pair<int, int>> q;

        // visit first row, and last row
        for (int j = 0; j < m; j++)
        {
            // for first row
            if (!vis[0][j] && grid[0][j] == 1)
            {
                // mark as visited
                vis[0][j] = 1;
                // push inside of queue, row, column
                q.push({0, j});
            }

            // for last row
            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
            {
                // mark as visited
                vis[n - 1][j] = 1;
                // push inside of queue, row, column
                q.push({n - 1, j});
            }
        }

        // visit first col, and last col
        for (int i = 0; i < n; i++)
        {
            // for first col
            if (!vis[i][0] && grid[i][0] == 1)
            {
                // mark as visited
                vis[i][0] = 1;
                // push inside of queue, row, column
                q.push({i, 0});
            }

            // for last col
            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            {
                // mark as visited
                vis[i][m - 1] = 1;
                // push inside of queue, row, column
                q.push({i, m - 1});
            }
        }

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            // pop element from queue
            q.pop();

            // traverse up,right,bottom,left of matrix
            for (int i = 0; i < 4; i++)
            {
                int new_row = row + del_row[i];
                int new_col = col + del_col[i];

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !vis[new_row][new_col] && grid[new_row][new_col] == 1)
                {
                    // mark as visited
                    vis[new_row][new_col] = 1;
                    // psuh inside queue
                    q.push({new_row, new_col});
                }
            }
        }

        // count how many land is left after traversal
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{

    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;
}