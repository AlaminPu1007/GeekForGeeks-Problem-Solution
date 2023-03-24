#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // define an priority queue,
        /*
            The priority_queue template in C++ has three template parameters.
            The first one is the type of the stored elements, which is pair<int, int> in this case.
            The second one is the container used to store the elements, which is vector<pair<int, int>>.
            The third one is the comparator used to compare elements in the queue.
            In this case, greater<pair<int, int>> is used as the comparator,
            which means that the highest-priority element is the one with the smallest value of dist.
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // define an distance array with infinite value
        vector<int> dist(V, INT_MAX);

        dist[S] = 0;
        // first value is weight, and last one is it's node
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;

            // removed item from priority queue
            pq.pop();

            for (auto item : adj[node])
            {
                int v = item[0];
                int w = item[1];

                if (distance + w < dist[v])
                {
                    dist[v] = distance + w;
                    // put distance, node
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main(void)
{
    Solution obj;
    int V = 3, E = 3;
    int S = 2;

    vector<vector<int>> adj[V] =
        {
            {{1, 1}, {2, 6}}, // This is node -> 0
            {{2, 3}, {0, 1}}, // This is node -> 1
            {{1, 3}, {0, 6}}, // This is node -> 2
        };

    vector<int> ans = obj.dijkstra(V, adj, S);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}