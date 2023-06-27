#include <bits/stdc++.h>
using namespace std;

// define disjoint dsa
class DisjointDSA
{
public:
    vector<int> rank, parents;

    DisjointDSA(int n)
    {
        rank.resize(n + 1, 0);
        parents.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }
    }
    // this method help us to find ultimate parent of givent node
    int findUltimateParent(int node)
    {
        if (node == parents[node])
            return node;
        else
            return parents[node] = findUltimateParent(parents[node]);
    }

    // method to update component with their ultimate parent
    void UnionByRank(int u, int v)
    {
        // find ultimate parent of u
        int ulp_u = findUltimateParent(u);

        // find ultimate parent of v
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        // update small component with bigger component
        if (rank[ulp_u] < rank[ulp_v])
        {
            parents[ulp_u] = ulp_v;
        }

        // update small component with bigger component
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parents[ulp_v] = ulp_u;
        }

        else
        {
            parents[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &str)
    {
        vector<vector<string>> ans;
        int n = str.size();

        unordered_map<string, int> Map;
        // initialize dis-joint data-structure
        DisjointDSA obj(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < str[i].size(); j++)
            {
                string mail = str[i][j];

                if (Map.find(mail) == Map.end())
                    Map[mail] = i;

                else
                {
                    // connected component
                    obj.UnionByRank(i, Map[mail]);
                }
            }
        }

        // merge accounts
        vector<string> merge[n];

        for (auto item : Map)
        {
            string mail = item.first;
            int node = obj.findUltimateParent(item.second);
            // cout << mail << " " << node << endl;
            merge[node].push_back(mail);
        }

        for (int i = 0; i < n; i++)
        {
            if (!merge[i].size())
                continue;

            vector<string> tmp;
            // sort array of string
            sort(merge[i].begin(), merge[i].end());

            // put name into tmp array
            tmp.push_back(str[i][0]);

            for (auto item : merge[i])
            {
                tmp.push_back(item);
            }

            ans.push_back(tmp);
        }

        // sort the answer -> without this answer is accepted
        // sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
                                       {"John", "j4@com"},
                                       {"Raj", "r1@com", "r2@com"},
                                       {"John", "j1@com", "j5@com"},
                                       {"Raj", "r2@com", "r3@com"},
                                       {"Mary", "m1@com"}};

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    for (auto acc : ans)
    {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++)
        {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}