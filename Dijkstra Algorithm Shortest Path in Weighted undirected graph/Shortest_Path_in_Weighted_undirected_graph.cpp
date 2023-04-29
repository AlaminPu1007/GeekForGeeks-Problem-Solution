/**
 * we will solved this problem by using Dijkstra’s Algorithm
 * we can use priority_queue or set data-structure
 * we will using priority queue for this problem
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        vector<int> dis(n + 1, INT_MAX), parent(n + 1);

        // define an priority queue
        // first for -> holding item as a pair, second for -> container and last on is comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i <= n; i++)
            // fill path with it's index
            parent[i] = i;

        for (auto item : edges)
        {
            int u = item[0];
            int v = item[1];
            int w = item[2];
            // make adjacency list of each node
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // put source node into pq
        pq.push({0, 1});
        dis[1] = 1;

        while (!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;

            // removed it from queue
            pq.pop();

            for (auto item : adj[node])
            {
                int adjNOde = item.first;
                int w = item.second;

                if (distance + w < dis[adjNOde])
                {
                    dis[adjNOde] = distance + w;
                    pq.push({distance + w, adjNOde});
                    // put it's parent(node) inside parent array
                    parent[adjNOde] = node;
                }
            }
        }

        // if we do not get last or end node
        if (dis[n] == INT_MAX)
            return {-1};

        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        // finally put the source node
        path.push_back(1);
        reverse(path.begin(), path.end());

        return path;
    }
};

int main(void)
{
    Solution obj;
    int n = 5, m = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    vector<int> res = obj.shortestPath(n, m, edges);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}