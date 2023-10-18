#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        // code here
        string ans;
        vector<int> adj[K];
        vector<int> inDegree(K, 0);
        // define queue data structure
        queue<int> q;

        for (int i = 0; i < N - 1; i++)
        {
            int len = min(dict[i].size(), dict[i + 1].size());

            string first_str = dict[i];
            string second_str = dict[i + 1];

            for (int j = 0; j < len; j++)
            {
                if (first_str[j] != second_str[j])
                {
                    // make an adjacency list
                    adj[first_str[j] - 'a'].push_back(second_str[j] - 'a');
                    break;
                }
            }
        }
        // calculate inDegree
        for (int i = 0; i < K; i++)
            for (auto item : adj[i])
                inDegree[item]++;

        for (int i = 0; i < K; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node + 'a');
            q.pop();

            // visit all adjacency list of node
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
    Solution obj;

    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    string ans = obj.findOrder(dict, N, K);

    cout << ans << endl;
    return 0;
}