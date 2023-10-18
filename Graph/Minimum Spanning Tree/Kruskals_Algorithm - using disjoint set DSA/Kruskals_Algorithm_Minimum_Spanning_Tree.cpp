#include <bits/stdc++.h>
using namespace std;

class DisjointAlgo
{
    vector<int> rank, parent;

public:
    DisjointAlgo(int n)
    {
        // for '0' base indexing system, we add + 1
        rank.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            // default every node ultimate parent it self
            parent[i] = i;
    };

    // method to find parent
    int findParent(int node)
    {
        if (node == parent[node])
            return node;

        // compress all node path with it ultimate parent
        else
            return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }

        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int minWt = 0;

        // it will hold {weight,{u,v }}
        vector<pair<int, pair<int, int>>> edges;

        // make an adjacency list of each node
        for (int i = 0; i < V; i++)
        {
            for (auto item : adj[i])
            {
                int wt = item[1];
                int adjNode = item[0];
                int node = i;

                // put adjacency list with their weight
                // it will hold for u = 1, v = 2, wt = 5
                // first -> {5, {1,2}}; second -> {5, {2, 1}}
                // our disjoint will avoid this duplication issue, don't panic
                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());

        // get disjoint data-structure
        DisjointAlgo obj(V);

        for (auto item : edges)
        {
            int u = item.second.first;
            int v = item.second.second;
            int wt = item.first;

            // if the {u -> v} do not belong to the same component
            if (obj.findParent(u) != obj.findParent(v))
            {

                // now count the cost of edges
                minWt += wt;

                // also make rank by union of given {u, v}
                obj.unionByRank(u, v);
            }
        }

        return minWt;
    }
};

int main(void)
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    // vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    vector<vector<int>> adj[V];

    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}