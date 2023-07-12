#include <bits/stdc++.h>
using namespace std;

// define disjoint dsa
class Disjoint
{
public:
    vector<int> rank, parent, size;
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        // every node is parent it self, default
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // find ultimate parent of given node
    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    // union by rank,(rank will hold height or level of root node(ultimate parent))
    void unionByRank(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;

            // increment rank height
            rank[ulp_u]++;
        }
    }

    // union by size, (it will hold the size of each root node(ultimate parent))
    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        int res = 0, n = grid.size();
        // define disjoint dsa
        Disjoint obj(n * n);

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        // connect component and get ultimate parent of them
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;

                for (int i = 0; i < 4; i++)
                {
                    int new_row = row + delRow[i];
                    int new_col = col + delCol[i];

                    if (isValid(new_row, new_col, n) && grid[new_row][new_col])
                    {
                        int nodeNo = row * n + col;
                        int adjNode = new_row * n + new_col;

                        // connected them, we will go through size instead of rank
                        // cause we do not need component height
                        obj.unionBySize(nodeNo, adjNode);
                    }
                }
            }
        }

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                // define set
                set<int> st;

                for (int i = 0; i < 4; i++)
                {
                    int new_row = row + delRow[i];
                    int new_col = col + delCol[i];

                    if (isValid(new_row, new_col, n))
                    {
                        if (grid[new_row][new_col] == 1)
                        {
                            st.insert(obj.findUltimateParent(new_row * n + new_col));
                        }
                    }
                }

                // we are at making one grid[new_row][new_col] = 1 (from 0)
                int componentSize = 1;

                for (auto item : st)
                {
                    componentSize += obj.size[item];
                }
                res = max(res, componentSize);
            }
        }
        // edge case, But if the matrix does not contain any cell with 0,
        for (int i = 0; i < n * n; i++)
            res = max(res, obj.size[obj.findUltimateParent(i)]);

        return res;
    }

private:
    bool isValid(int row, int col, int n)
    {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
};

int main(void)
{
    vector<vector<int>> grid = {
        // {1, 1, 0, 1, 1, 0},
        // {1, 1, 0, 1, 1, 0},
        // {1, 1, 0, 1, 1, 0},
        // {0, 0, 1, 0, 0, 0},
        // {0, 0, 1, 1, 1, 0},
        // {0, 0, 1, 1, 1, 0},
        {1, 1},
        {1, 1},
    };

    Solution obj;
    int ans = obj.MaxConnection(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
}