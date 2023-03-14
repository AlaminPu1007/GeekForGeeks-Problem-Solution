#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> &pre)
    {
        vector<int> ans;
        // define an adjacency list
        vector<int> adj[n];
        for (auto item : pre)
        {
            // This item[1] should be perform before item[0]
            // item[1] ---> item[0]
            adj[item[1]].push_back(item[0]);
        }

        // print list of task

        // for(int i = 0; i < n; i++)
        // {
        //     cout<<"for "<<i<<" -> ";
        //     for(auto item: adj[i])
        //     {
        //         cout<<item<<" ";
        //     }
        //     cout<<endl;
        // }

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
            return ans;

        return {};
    }
};

int main()
{

    int N = 4;
    int M = 3;

    vector<vector<int>> prerequisites = {
        {0, 1}, {1, 2}, {2, 3}};
    // 	prerequisites[0].push_back(0);
    // 	prerequisites[0].push_back(1);

    // 	prerequisites[1].push_back(1);
    // 	prerequisites[1].push_back(2);

    // 	prerequisites[2].push_back(2);
    // 	prerequisites[2].push_back(3);

    Solution obj;
    vector<int> ans = obj.findOrder(N, M, prerequisites);

    for (auto task : ans)
    {
        cout << task << " ";
    }
    cout << endl;
    return 0;
}
