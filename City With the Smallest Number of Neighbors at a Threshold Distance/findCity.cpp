#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> distCity(n, vector<int>(n, INT_MAX));

        // copy edges into distCity matrix array
        for (auto it : edges)
        {
            // making an matrix i->j = weight
            distCity[it[0]][it[1]] = it[2];
            // making an matrix j->i = weight
            distCity[it[1]][it[0]] = it[2];
        }

        // put self node as 0
        for (int i = 0; i < n; i++)
            distCity[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    /*
                     If either distCity[i][k] or distCity[k][j] is "infinity,"
                     it means that there is no direct path from vertex i to vertex k or from vertex k to vertex j.
                     In such cases, the code continues to the next iteration of the loop without updating the distCity[i][j] value,
                     as there is no valid intermediate vertex k that can improve the path.
                     */
                    if (distCity[i][k] == INT_MAX || distCity[k][j] == INT_MAX)
                        continue;

                    distCity[i][j] = min(distCity[i][j], distCity[i][k] + distCity[k][j]);
                }
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << distCity[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int countThreshold = n;
        int city = -1;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (distCity[i][j] <= distanceThreshold)
                    count++;
            }

            if (count <= countThreshold)
            {
                countThreshold = count;
                city = i;
            }
        }

        return city;
    }
};

int main()
{

    int n = 5;
    int m = 6;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int distanceThreshold = 2;

    Solution obj;
    int cityNo = obj.findCity(n, m, edges, distanceThreshold);
    cout << "The answer is node: " << cityNo << endl;

    return 0;
}
