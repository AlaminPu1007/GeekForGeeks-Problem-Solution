/*
    // set always store unique value as well as put data within ascending order
    // we always get lower weighted value from set,
    // first-> weight, second-> node
    // ex: first insert->set.insert({2, 3}),
    // second insert -> set.insert({1, 5}) ---> this one will get first because of it's weight value;
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V, INT_MAX);
        // define an set data-structure
        // first item-> weight, second item-> node
        set<pair<int, int>> st;

        dis[S] = 0;
        st.insert({0, S});

        while (!st.empty())
        {
            // st.begin() -> point an references,
            // and *(st.begin()) -> will convert into value
            auto it = *(st.begin());

            // cout << it.first << " " << it.second << " from set" << endl;

            int node = it.second;
            int distance = it.first;

            st.erase(it);

            for (auto item : adj[node])
            {
                int w = item[1];
                int adjNode = item[0];

                if (distance + w < dis[adjNode])
                {
                    // if any node has already value instead of INT_MAX
                    // we need to removed it from set
                    if (dis[adjNode] == INT_MAX)
                        st.erase({dis[adjNode], adjNode});

                    dis[adjNode] = distance + w;
                    st.insert({dis[adjNode], adjNode});

                    // cout << dis[adjNode] << " " << adjNode << " from after store into set" << endl;
                }
            }
        }

        return dis;
    }
};

int main(void)
{
    Solution obj;
    int V = 3, E = 3;
    vector<vector<int>> adj[V] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int S = 2;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (auto item : res)
        cout << item << " ";

    return 0;
}
