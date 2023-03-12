
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfsCycle(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        // mark node as visited
        vis[node] = 1;
        // mark as well as path visited
        pathVis[node] = 1;

        // traverse adjacency list of node
        for (auto item : adj[node])
        {
            if (!vis[item])
            {
                // make dfs recursive called
                // if any of recursive is return true, then return true
                if (dfsCycle(item, adj, vis, pathVis))
                    return true;
            }
            // if node is already visited and path also visited
            //  means, this is an cycle
            else if (pathVis[item])
                return true;
        }
        // back track to mark path as unvisited
        pathVis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0}, pathVis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // called DFS Method to detect cycle
                if (dfsCycle(i, adj, vis, pathVis))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> adj[] = {
        {},
        {2},
        {3},
        {4, 7},
        {5},
        {6},
        {},
        {5},
        {9},
        {10},
        {8},
    };
    bool res = obj.isCyclic(11, adj);

    cout << res << endl;
    return 0;
}