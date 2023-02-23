#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        // visit first row, and last row
        for (int i = 0; i < m; i++)
        {
            // for first row
            if (!vis[0][i] && mat[0][i] == 'O')
            {
                // make visit array as visited
                vis[0][i] = 1;
                // push inside of queue, (row, col)
                q.push({0, i});
            }

            // for last row
            if (!vis[n - 1][i] && mat[n - 1][i] == 'O')
            {
                // make visit array as visited
                vis[n - 1][i] = 1;
                // push inside of queue, (row, col)
                q.push({n - 1, i});
            }
        }

        // visit first col, last col
        for (int j = 0; j < n; j++)
        {
            // for first column
            if (!vis[j][0] && mat[j][0] == 'O')
            {
                // make visit array as visited
                vis[j][0] = 1;
                // push inside of queue, (row, col)
                q.push({j, 0});
            }

            // for last column
            if (!vis[j][m - 1] && mat[j][m - 1] == 'O')
            {
                // make visit array as visited
                vis[j][m - 1] = 1;
                // push inside of queue, (row, col)
                q.push({j, m - 1});
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            // pop queue
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int new_row = row + del_row[i];
                int new_col = col + del_col[i];

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !vis[new_row][new_col] && mat[new_row][new_col] == 'O')
                {
                    vis[new_row][new_col] = 1;
                    q.push({new_row, new_col});
                }
            }
        }

        // fill left 'O' with 'X'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};

int main()
{

    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};

    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}