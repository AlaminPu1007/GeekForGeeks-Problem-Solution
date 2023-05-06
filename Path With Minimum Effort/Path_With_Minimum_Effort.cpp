#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> iPair;

class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        // define an priority-queue
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        // put source node with 0 distance
        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        // define array for traverse matrix with 4 direction
        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int distance = pq.top().first;
            // removed item from pq
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return distance;

            // Traverse array
            for (int i = 0; i < 4; i++)
            {
                int new_row = row + del_row[i];
                int new_col = col + del_col[i];
                // check boundary
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m)
                {
                    int diff = abs(heights[row][col] - heights[new_row][new_col]);
                    int newEffort = max(distance, diff);

                    if (newEffort < dis[new_row][new_col])
                    {
                        dis[new_row][new_col] = newEffort;
                        pq.push({newEffort, {new_row, new_col}});
                    }
                }
            }
        }

        return 0;
    }
};

int main(void)
{
    Solution obj;
    vector<vector<int>> grid = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    int res = obj.MinimumEffort(grid);
    cout << res << endl;
    return 0;
}