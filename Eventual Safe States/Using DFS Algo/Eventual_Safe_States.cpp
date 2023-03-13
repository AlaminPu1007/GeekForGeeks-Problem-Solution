#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0), pathVis(V, 0), checkPath(V, 0);
        // store all safe node together
        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // make DFS called
                DFS(i, vis, pathVis, checkPath, adj);
            }
        }

        for (int i = 0; i < V; i++)
            if (checkPath[i])
                safeNodes.push_back(i);

        return safeNodes;
    }

private:
    bool DFS(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &checkPath, vector<int> adj[])
    {
        // mark as visited as well as path visited
        vis[node] = 1;
        pathVis[node] = 1;
        // mark safe node as initial unsafe
        checkPath[node] = 0;

        for (auto item : adj[node])
        {
            if (!vis[item])
            {
                // if any of them is true, then return true
                if (DFS(item, vis, pathVis, checkPath, adj))
                    return true;
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            else if (pathVis[item])
                return true;
        }

        // if any cycle is not present, then removed it from pathVis,
        pathVis[node] = 0;
        // mark it's an safe node
        checkPath[node] = 1;

        return false;
    }
};

int main(void)
{
    Solution obj;
    int V = 12;

    vector<int> adj[12] = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};

    vector<int> res = obj.eventualSafeNodes(V, adj);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}