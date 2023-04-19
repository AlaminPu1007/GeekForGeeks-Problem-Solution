#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dis(V, 1e8);
        dis[S] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto item : edges)
            {
                int u = item[0];
                int v = item[1];
                int wt = item[2];

                if (dis[u] != 1e8 && dis[u] + wt < dis[v])
                    dis[v] = dis[u] + wt;
            }
        }

        // N'th relaxation to check negative cycle
        for (auto item : edges)
        {
            int u = item[0];
            int v = item[1];
            int wt = item[2];

            if (dis[u] != 1e8 && dis[u] + wt < dis[v])
                return {-1};
        }

        return dis;
    }
};

int main(void)
{
    Solution obj;
    int S = 0, V = 6;
    vector<vector<int>> edges = {{3, 2, 6}, {5, 3, 1}, {0, 1, 5}, {1, 5, -3}, {1, 2, -2}, {3, 4, -2}, {2, 4, 3}};
    vector<int> ans = obj.bellman_ford(V, edges, S);
    for (auto item : ans)
        cout << item << " ";
    return 0;
}