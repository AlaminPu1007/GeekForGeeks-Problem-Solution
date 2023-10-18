#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> iPair;
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // Code here

        // define distance array, which on hold our distance for every node from source
        vector<int> dist(n, INT_MAX);
        // define an priority queue to hole {step, {node, distance}}
        queue<iPair> q;

        // define an adjacency list of each node
        vector<pair<int, int>> adj[n];

        for (auto item : flights)
        {
            // cout << item[0] << " " << item[1] << " " << item[1] << endl;
            // adj list will hold,  item[0](u) -> item[1](v), item[2](cost)
            adj[item[0]].push_back({item[1], item[2]});
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (auto item : adj[i])
        //     {
        //         cout << item.first << " " << item.second << endl;
        //     }
        // }

        // store source node into queue
        // first -> step(k), {node -> 0, distance -> 0}
        q.push({0, {src, 0}});
        // also put source node distance 0
        dist[src] = 0;

        while (!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second.first;
            int distance = q.front().second.second;

            // removed item from queue
            q.pop();

            // We stop the process as soon as the limit for the stops reaches.
            if (steps > K)
                continue;

            // traverse adjacency list of each node
            for (auto item : adj[node])
            {
                if (distance + item.second < dist[item.first] && steps <= K)
                {
                    dist[item.first] = distance + item.second;
                    // push into queue
                    q.push({steps + 1, {item.first, distance + item.second}});
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;

        return dist[dst];
    }
};

int main(void)
{
    Solution obj;
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dst = 3, k = 1;
    int res = obj.CheapestFLight(n, flights, src, dst, k);
    cout << res << endl;
    return 0;
}