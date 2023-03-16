/*
    for a DAG(directed acyclic graph -> no cycle is present) topo sort is best to find sortes path.
    which is more sufficient than dijakstra algorithm.

    toposort has two approach, one is DFS using stack data strucute,
    another one is BFS using queue data structure
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void topoSort(int startNode, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[startNode] = 1;
        // traverse it's adjacency list
        for (auto item : adj[startNode])
        {
            int node = item.first;
            if (!vis[node])
            {
                topoSort(node, adj, vis, st);
            }
        }
        // after completed to visit adjacency list of startNode
        // now push it into stack for topological sort
        st.push(startNode);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // define an adjacency list of graph with pairs
        // first value will be node value and last value will be it's weight
        vector<pair<int, int>> adj[N];

        vector<int> ans;
        vector<int> vis(N, 0);
        // define an stack data-structure
        stack<int> st;

        // make an adjacency list from given matrix of edges
        for (int i = 0; i < M; i++)
        {
            // every vector has three value
            // first is indicate 'u'
            int u = edges[i][0];
            // next one is indicate 'v'
            int v = edges[i][1];
            // and the last one is indicate it's weight
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // for(int i = 0; i < N; i++)
        // { cout<<i<<" -> ";
        //     for(auto item: adj[i])
        //         cout<<item.first<<" ";
        //         cout<<endl;
        // }

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                // called DFS method of TOPO-SORT
                topoSort(i, adj, vis, st);
            }
        }

        // //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
        // distance from the source vertex after relaxation of a particular node.
        vector<int> dis(N);

        for (int i = 0; i < N; i++)
        {
            dis[i] = 1e9;
        }

        // mark source node distance is 0, (src always 0)
        dis[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            // remove it from stack
            st.pop();

            // traverse through node it's adjacency list
            for (auto item : adj[node])
            {
                // first value is node value
                int v = item.first;
                // second value it's weight
                int wt = item.second;

                if (dis[node] + wt < dis[v])
                    // update dis[v]
                    dis[v] = wt + dis[node];
            }
        }

        for (int i = 0; i < N; i++)
            if (dis[i] == 1e9)
                dis[i] = -1;

        return dis;
    }
};

int main(void)
{
    Solution obj;
    int n = 6, m = 7;
    vector<vector<int>> edge = {
        {0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<int> ans = obj.shortestPath(n, m, edge);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}