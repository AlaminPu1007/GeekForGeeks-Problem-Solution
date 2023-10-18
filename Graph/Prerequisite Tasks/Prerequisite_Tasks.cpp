#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int n, vector<pair<int, int>> &pre)
    {
        vector<int> ans;
        // define an adjacency list
        vector<int> adj[n];
        for (auto item : pre)
            // This item[1] should be perform before item[0]
            // item[1] ---> item[0]
            adj[item.first].push_back(item.second);

        // logic for topological sort
        int inDegree[n] = {0};
        queue<int> q;

        // count in-degree of node
        for (int i = 0; i < n; i++)
            for (auto item : adj[i])
                inDegree[item]++;

        for (int i = 0; i < n; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            // push into ans
            ans.push_back(node);

            for (auto item : adj[node])
            {
                // removed it degree from inDegree
                inDegree[item]--;

                if (!inDegree[item])
                    q.push(item);
            }
        }

        if (ans.size() == n)
            return true;

        return false;
    }
};

int main()
{
    int N = 4;

    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    Solution obj;

    bool ans = obj.isPossible(N, prerequisites);
    cout << ans << endl;

    return 0;
}
