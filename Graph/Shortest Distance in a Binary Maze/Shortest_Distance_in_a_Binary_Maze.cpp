#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first && source.second == destination.second)
            return 0;

        int n = grid.size(), m = grid[0].size();
        // define queue Data-structure to hold distance with row, col
        queue<pair<int, pair<int, int>>> q;
        // define an distance array with infinity value
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // put source into queue, it will hold first as node distance
        // then hold row, col value of node
        q.push({0, {source.first, source.second}});

        // put source node distance as 0
        dist[source.first][source.second] = 0;

        // define del_row and del_col to visit matrix as four distance according to row,col value
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int distance = q.front().first;

            // removed item from queue after getting it
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                // get new-row and new-col
                int new_row = row + del_row[i];
                int new_col = col + del_col[i];

                // check boundary to avoid overlap of given grid(matrix)
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == 1)
                {
                    if (distance + 1 < dist[new_row][new_col])
                    {
                        // whenever we reached at our source destination then return with minimum distance
                        if (new_row == destination.first && new_col == destination.second)
                            return distance + 1;
                        // update dist with new minimum weight from previous
                        dist[new_row][new_col] = distance + 1;
                        // push this new item into queue
                        q.push({distance + 1, {new_row, new_col}});
                    }
                }
            }
        }
        return -1;
    }
};

int main(void)
{
    Solution obj;
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};
    int res = obj.shortestPath(grid, source, destination);
    cout << res << endl;
    return 0;
}