
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1), parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        else
            parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;

        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;

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
    int numProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet obj(V);

        int count = 0, n = adj.size(), m = adj[0].size();

        for (int row = 0; row < n; row++)

            for (int col = 0; col < m; col++)

                if (adj[row][col])
                    obj.unionByRank(row, col);

        for (int i = 0; i < V; i++)
        {
            // we can also find by  obj.findParent(i) -> has time complexity O(4α) almost constant time O(1)
            // obj.parent[i] -> has constant time complexity
            if (obj.parent[i] == i)
                count++;
        }

        return count;
    }
};

int main(void)
{
    Solution obj;
    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    int res = obj.numProvinces(adj, 3);
    cout << res << endl;
    return 0;
}