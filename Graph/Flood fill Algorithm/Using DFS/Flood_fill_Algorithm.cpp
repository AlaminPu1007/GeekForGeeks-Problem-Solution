#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int iniColor = image[sr][sc];

        vector<vector<int>> ans = image;

        // define new row,col to visit array x and y axis
        int del_row[] = {-1, 0, +1, 0};
        int del_col[] = {0, +1, 0, -1};

        Dfs_Algo(image, ans, sr, sc, newColor, del_row, del_col, iniColor);

        return ans;
    }

private:
    void Dfs_Algo(vector<vector<int>> &image, vector<vector<int>> &ans, int row, int col, int newColor, int del_row[], int del_col[], int iniColor)
    {
        int row_size = image.size();
        int col_size = image[0].size();

        ans[row][col] = newColor;

        // visit x,y axis and mark new-color
        for (int i = 0; i < 4; i++)
        {
            int new_row = row + del_row[i];
            int new_col = col + del_col[i];

            if (new_row >= 0 && new_row < row_size && new_col >= 0 && new_col < col_size && image[new_row][new_col] == iniColor && ans[new_row][new_col] != newColor)
            {
                Dfs_Algo(image, ans, new_row, new_col, newColor, del_row, del_col, iniColor);
            }
        }
    }
};

int main(void)
{
    vector<vector<int>> image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    // sr = 1, sc = 1, newColor = 2
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}