#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        vector<int> res;
        vector<int> vis(n, 0);
        vector<int> timeOfInsertion(n), lowestOfInsertion(n);
        vector<int> markArticulation(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                DFS(i, -1, adj, vis, timeOfInsertion, lowestOfInsertion, markArticulation);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (markArticulation[i] == 1)
                res.push_back(i);
        }

        if (!res.size())
            return {-1};

        return res;
    }

private:
    int count = 1;

    void DFS(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &timeOfInsertion, vector<int> &lowestOfInsertion, vector<int> &mark)
    {
        // first mark node as visited
        vis[node] = 1;
        timeOfInsertion[node] = count;
        lowestOfInsertion[node] = count;
        count++;

        int child = 0;

        // traverse through adjacency list of graph
        for (auto adjNode : adj[node])
        {

            if (adjNode == parent)
                continue;

            if (!vis[adjNode])
            {
                // called DFS method
                DFS(adjNode, node, adj, vis, timeOfInsertion, lowestOfInsertion, mark);

                // whenever we get back after completed recursion, we need update lowest time of insertion
                lowestOfInsertion[node] = min(lowestOfInsertion[node], lowestOfInsertion[adjNode]);

                // check for articulation point for node, and we skip for first node
                if (lowestOfInsertion[adjNode] >= timeOfInsertion[node] && parent != -1)
                {
                    mark[node] = 1;
                }

                // count child for each node
                child++;
            }
            // do for visited node
            else
            {
                lowestOfInsertion[node] = min(lowestOfInsertion[node], timeOfInsertion[adjNode]);
            }
        }

        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }
};

int main()
{

    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4}, {2, 4}, {2, 3}, {3, 4}};

    vector<int> adj[n];
    for (auto it : edges)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> nodes = obj.articulationPoints(n, adj);
    for (auto node : nodes)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}