#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool DFS(int node, int colorValue, int colors[], vector<int> adj[])
    {
        // mark colors with value
        colors[node] = colorValue;

        // traverse adjacency list of node
        for (auto item : adj[node])
        {
            // if node is not color yet, then mark it opposite color of root node color, 0->1 or vise versa
            if (colors[item] == -1)
            {
                // if any of DFS return false, no further DFS called is required
                if (!DFS(item, !colorValue, colors, adj))
                    return false;
            }
            // if item(node) is already color and have similar color with root node
            else if (colors[item] == colors[node])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int colors[V];
        // fill colors with -1, as initial value, means, unvisited
        for (int i = 0; i < V; i++)
            colors[i] = -1;

        for (int i = 0; i < V; i++)
        {
            if (colors[i] == -1)
            {
                if (!DFS(i, 0, colors, adj))
                    return false;
            }
        }

        return true;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(void)
{
    Solution obj;

    // V = 4, E = 4
    vector<int> adj[4];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    bool ans = obj.isBipartite(4, adj);
    cout << ans << endl;

    return 0;
}