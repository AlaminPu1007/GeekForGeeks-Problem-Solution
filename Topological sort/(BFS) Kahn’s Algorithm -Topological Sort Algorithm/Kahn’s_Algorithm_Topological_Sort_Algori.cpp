#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // define in-degree of each node, with initialize-0
        int inDegree[V] = {0};

        // calculate each node in-degree
        for (int i = 0; i < V; i++)
        {
            // ex: 4 -> {0, 1}, for inDegree[0] and inDegree[1] will be increment by 1
            for (auto item : adj[i])
            {
                inDegree[item]++;
            }
        }
        // define q
        queue<int> q;

        // if any of node has no intDegree, that will be our initial topo sorting node
        for (int i = 0; i < V; i++)
        {
            if (!inDegree[i])
                q.push(i);
        }

        // define ans vector
        vector<int> ans;

        // loop through q, until it's became empty
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // push it inside answer vector, it will be our topo sorting node
            ans.push_back(node);

            // loop through adjacency of node and decrement it's vertices by 1
            // after decrement it by 1, and any of them value is equal to 0, then push it inside q, so on..
            for (auto item : adj[node])
            {
                inDegree[item]--;
                if (!inDegree[item])
                    q.push(item);
            }
        }
        return ans;
    }
};

int main(void)
{

    // V = 6;
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;
    Solution obj;
    vector<int> ans = obj.topoSort(V, adj);

    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}