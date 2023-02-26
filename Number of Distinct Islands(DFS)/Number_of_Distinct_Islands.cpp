#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size(), m = grid[0].size();

        // define an visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // define an set array, it will hold unique result
        set<vector<pair<int, int>>> st;

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    // define pair vector to hold row,col
                    vector<pair<int, int>> eachVec;
                    // made an DFS method called
                    DFS(n, m, i, j, vis, grid, eachVec, i, j, del_row, del_col);
                    // put inside set after get islands
                    st.insert(eachVec);
                }
            }
        }

        return st.size();
    }

private:
    void DFS(int n, int m, int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &eachVec, int base_row, int base_col, int del_row[], int del_col[])
    {
        // make every visit array as visited
        vis[row][col] = 1;
        eachVec.push_back({row - base_row, col - base_col});

        // vis matrix at top,right,bottom, left direction
        for (int i = 0; i < 4; i++)
        {
            // get new-row, new-col accordion to row, col
            int new_row = row + del_row[i];
            int new_col = col + del_col[i];

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !vis[new_row][new_col] && grid[new_row][new_col] == 1)
            {
                // make dfs method call
                DFS(n, m, new_row, new_col, vis, grid, eachVec, base_row, base_col, del_row, del_col);
            }
        }
    }
};

int main(void)
{
    Solution obj;
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {
            1,
            1,
            0,
            1,
            1,
        }};
    int res = obj.countDistinctIslands(grid);
    cout << res << endl;
    return 0;
}