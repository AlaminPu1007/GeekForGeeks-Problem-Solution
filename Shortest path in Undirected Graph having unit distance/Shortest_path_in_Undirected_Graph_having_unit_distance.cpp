#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];

        // make adjacency list of each node
        for (auto item : edges)
        {
            adj[item[0]].push_back(item[1]);
            adj[item[1]].push_back(item[0]);
        }

        // for (int i = 0; i < N; i++)
        // {
        //     cout << "List " << i << " -> ";
        //     for (auto item : adj[i])
        //         cout << item << " ";
        //     cout << endl;
        // }

        // define queue data structure
        queue<int> q;

        // define distance array
        vector<int> dist(N, INT_MAX);

        // push initial value with it's weight
        // initial value is always 0
        q.push(src);
        // set dist value for src value is 0
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            // now remove item from queue data-structure
            q.pop();

            for (auto item : adj[node])
            {
                if (dist[node] + 1 < dist[item])
                {
                    dist[item] = 1 + dist[node];
                    // also push in queue
                    q.push(item);
                }
            }
        }

        for (int i = 0; i < N; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;

        return dist;
    }
};

int main(void)
{
    Solution obj;
    int n = 9, m = 10, src = 0;
    vector<vector<int>> arr = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    vector<int> ans = obj.shortestPath(arr, n, m, src);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}