/**
 * To solve this problem we need dijkstra algorithm
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> iPair;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // code here
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        vector<iPair> adj[n];

        // make an adjacency list of given roads
        for (auto item : roads)
        {
            adj[item[0]].push_back({item[1], item[2]});
            adj[item[1]].push_back({item[0], item[2]});
        }

        // define an priority queue
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        // put source node into pq
        // it will hold {distance, node}
        pq.push({0, 0});
        // mark source node distance from itself
        dist[0] = 0;
        // put no of ways as 1
        ways[0] = 1;

        // Define modulo value
        long long mod = (long long)(1e9 + 7);

        while (!pq.empty())
        {
            int node = pq.top().second;
            // int distance = pq.top().first;

            // removed item from queue
            pq.pop();

            // traverse adjacency list of node
            for (auto item : adj[node])
            {
                // do main logic here
                // dist[node] -> without this portion we will get wrong answer
                int isMinDistance = item.second + dist[node];

                if (isMinDistance < dist[item.first])
                {
                    // update dist array with minimum reaching value
                    dist[item.first] = isMinDistance;
                    // put also into queue
                    pq.push({isMinDistance, item.first});
                    // put what ever ways[node] into new ways[item.first]
                    // cause we are first time arriving with shortest path
                    ways[item.first] = ways[node];
                }

                // update no of ways
                else if (isMinDistance == dist[item.first])
                    ways[item.first] = (ways[item.first] + ways[node]) % mod;
            }
        }
        // for (auto item : ways)
        //     cout << item << " ";
        // cout << endl;
        return ways[n - 1] % mod;
    }
};

int main(void)
{
    Solution obj;
    int n = 7, m = 10;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    int res = obj.countPaths(n, roads);
    cout << res << endl;
    return 0;
}