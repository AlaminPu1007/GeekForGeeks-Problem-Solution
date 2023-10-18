#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void DFS(int node, vector<int> adj[], stack<int> &s, int vis[])
    {
        // mark node as visited
        vis[node] = 1;

        for (auto item : adj[node])
        {
            if (!vis[item])
            {
                DFS(item, adj, s, vis);
            }
        }
        s.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> ans;
        stack<int> s;
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // make DFS method called for each component(graph)
                DFS(i, adj, s, vis);
            }
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main(void)
{
    Solution obj;
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    vector<int> res = obj.topoSort(V, adj);

    for (auto item : res)
    {
        cout << item << " ";
    }
    return 0;
}