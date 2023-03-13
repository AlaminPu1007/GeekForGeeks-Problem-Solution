#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {

        vector<int> adjRev[V];
        vector<int> ans;
        int inDegree[V] = {0};

        // we need to reverse adjacency list of each node
        // by reversing it, we get the terminal node with in-degree 0
        // and moving forward through this terminal node
        // this technique gives us more efficient way to find safest node

        for (int i = 0; i < V; i++)
        {
            for (auto item : adj[i])
            {
                // reverse each node adjacency list
                // where i is root node and item is adj list
                adjRev[item].push_back(i);
                // count each node in-degree
                inDegree[i]++;
            }
        }

        // define an queue data-structure
        queue<int> q;

        for (int i = 0; i < V; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto item : adjRev[node])
            {
                inDegree[item]--;
                if (!inDegree[item])
                    q.push(item);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main(void)
{
    Solution obj;
    vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};
    int V = 12;

    vector<int> ans = obj.eventualSafeNodes(V, adj);

    for (auto item : ans)
        cout << item << " ";
}