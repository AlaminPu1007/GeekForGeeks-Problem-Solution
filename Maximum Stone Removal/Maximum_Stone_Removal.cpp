#include <bits/stdc++.h>
using namespace std;

// create Disjoint data-structure
class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
            return node;
        else
            return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        int res = 0;

        int maxRow = 0, maxCol = 0;
        // get grid or matrix size
        for (auto item : stones)
        {
            maxRow = max(maxRow, item[0]);
            maxCol = max(maxCol, item[1]);
        }

        // define disjoint dsa
        DisjointSet obj(maxRow + maxCol + 1);

        // define hash-map to get parent
        unordered_map<int, int> Map;

        // connected component
        for (auto item : stones)
        {
            int rowNode = item[0];
            int colNode = item[1] + maxRow + 1;

            obj.UnionBySize(rowNode, colNode);

            // for row
            Map[rowNode] = 1;
            Map[colNode] = 1;
        }

        for (auto item : Map)
            if (obj.findUltimateParent(item.first) == item.first)
                res++;

        return n - res;
    }
};

int main()
{

    int n = 6;
    vector<vector<int>> stones = {
        {0, 0}, {0, 2}, {1, 3}, {3, 1}, {3, 2}, {4, 3}};

    Solution obj;
    int ans = obj.maxRemove(stones, n);
    cout << "The maximum number of stones we can remove is: " << ans << endl;
    return 0;
}