#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int res = 0;
        vector<int> vis(V, 0);
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

        // it will hold, {weight, node}
        pq.push({0, 0});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;

            // pop element from pq
            pq.pop();

            if (vis[node])
                continue;

            // mark node as visited
            vis[node] = 1;
            res += wt;

            // traversal of adjacency
            for (auto item : adj[node])
            {
                int adjNode = item[0];
                int adjWeight = item[1];

                // insert into pq
                if (!vis[adjNode])
                    pq.push({adjWeight, adjNode});
            }
        }

        return res;
    }
};
int main(void)
{
    Solution obj;
    int n = 5, m = 5;

    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    // it will hold list of weight with their nodes node -> {outgoing node, weight}
    // 0 -> {1, 2},
    vector<vector<int>> adj[n];

    // making adjacency list using node
    for (auto item : edges)
    {
        cout << item[0] << " " << item[1] << " " << item[2] << endl;
        // it will hold two value
        vector<int> tmp(2);

        tmp[0] = item[1];
        tmp[1] = item[2];
        adj[item[0]].push_back(tmp);

        // it's an undirected graph, we need put other node as well
        tmp[0] = item[0];
        tmp[1] = item[2];
        adj[item[1]].push_back(tmp);
    }

    cout << obj.spanningTree(n, adj)<<endl;

    return 0;
}