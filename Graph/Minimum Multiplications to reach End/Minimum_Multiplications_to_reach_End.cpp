#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // define distance array for all node
        // where node list from 0 -> 10^4(100000)
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q;

        // Create a queue for storing the numbers as a result of multiplication
        // of the numbers in the array and the start number.
        q.push({start, 0});

        dist[start] = 0;

        int mod = 100000;

        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;

            q.pop();

            for (auto item : arr)
            {
                int multiplication = (item * node) % mod;
                if (steps + 1 < dist[multiplication])
                {
                    dist[multiplication] = steps + 1;

                    // Whenever we reach the end number
                    // return the calculated steps
                    if (multiplication == end)
                        return steps + 1;

                    q.push({multiplication, steps + 1});
                }
            }
        }

        return -1;
    }
};

int main(void)
{
    // Driver Code.
    int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    Solution obj;

    int ans = obj.minimumMultiplications(arr, start, end);

    cout << ans;
    cout << endl;

    return 0;
}