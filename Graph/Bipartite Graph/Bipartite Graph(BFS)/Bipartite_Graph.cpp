#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool BFS(int startNode, int colors[], vector<int> adj[])
    {
        // define queue data-structure
        queue<int> q;

        // mark start-node as initial color
        colors[startNode] = 0;
        
        // put it in queue
        q.push(startNode);

        while (!q.empty())
        {
            // get node from queue
            int node = q.front();
            q.pop();

            // start traverse adjacency according to node
            for (auto item : adj[node])
            {
                // if node is not colored yet, then mark is opposite color of root node
                if (colors[item] == -1)
                {
                    colors[item] = !colors[node];
                    // push into queue also
                    q.push(item);
                }
                // is the adjacent guy having the same color
                // someone did color it on some other path
                else if (colors[item] == colors[node])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int colors[V];

        for (int i = 0; i < V; i++)
            colors[i] = -1;

        for (int i = 0; i < V; i++)
        {
            // if not coloured
            if (colors[i] == -1)
            {
                if (!BFS(i, colors, adj))
                {
                    return false;
                }
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