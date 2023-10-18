/**
 * Dijkstra’s Shortest Path algorithm and Bellman-Ford algorithm are single-source shortest path algorithms
 * where we are given a single source node and are asked to find out the shortest path to every other node
 * from that given source. But in the Floyd Warshall algorithm, we need to figure out the shortest distance from each node to
 * every other node.
 *
 * Basically, the Floyd Warshall algorithm is a multi-source shortest path algorithm
 * and it helps to detect negative cycles as well.
 * The shortest path between node u and v necessarily means the path(from u to v)
 * for which the sum of the edge weights is minimum.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // by default every item has -1 value, fill with larger value
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9;

                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        // fill actual matrix with shortest path value using floyd warshall algorithm

        // first loop indicated via from i->j
        // A cycle is called a negative cycle if the sum of all its weights becomes negative.

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        // if we want to detect negative cycle, just check a self node has value less than 0 (node < 0)
        // for (int i = 0; i < n; i++)
        // {
        //     if (matrix[i][i] < 0)
        //     {
        //         cout << "This node contain an negative cycle" << endl;
        //     }
        // }

        // if we not reach at any node fill with -1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                    matrix[i][j] = -1;
            }
        }

        // print matrix
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
};

int main(void)
{
    Solution obj;
    vector<vector<int>> matrix = {
        {0, 1, 7}, {1, 0, 6}, {-1, -1, 0}};
    obj.shortest_distance(matrix);
    return 0;
}