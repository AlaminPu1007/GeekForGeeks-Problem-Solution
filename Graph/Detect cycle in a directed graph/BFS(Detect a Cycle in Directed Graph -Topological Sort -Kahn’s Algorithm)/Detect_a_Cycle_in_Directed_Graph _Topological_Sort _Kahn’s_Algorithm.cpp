#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        int inDegree[V] = {0};

        for (int i = 0; i < V; i++)
            for (auto item : adj[i])
                inDegree[item]++;

        queue<int> q;

        for (int i = 0; i < V; i++)
            if (!inDegree[i])
                q.push(i);

        int count = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (auto item : adj[node])
            {
                inDegree[item]--;
                if (!inDegree[item])
                    q.push(item);
            }
        }

        if (count == V)
            return false;

        return true;
    }
};

int main()
{
    vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
    int V = 6;
    Solution obj;
    bool ans = obj.isCyclic(V, adj);
    if (ans)
        cout << "True";
    else
        cout << "Flase";
    cout << endl;
    return 0;
}