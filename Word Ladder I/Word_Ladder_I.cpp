#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        // define queue
        queue<pair<string, int>> q;
        // push strt word into queue
        q.push({startWord, 1});
        // removed it from set
        st.erase(startWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int dis = q.front().second;

            // removed it from queue
            q.pop();
            // cout<<word <<" "<< targetWord<<endl;
            if (word == targetWord)
                return dis;

            int len = word.size();
            for (int i = 0; i < len; i++)
            {
                char originalChar = word[i];
                // loop through a-z
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // word is found
                    // need to remove it from set, and push into queue
                    if (st.find(word) != st.end())
                    {
                        // removed
                        st.erase(word);
                        // push into queue
                        q.push({word, dis + 1});
                    }
                }
                // get back original word after modified
                word[i] = originalChar;
            }
        }
        return 0;
    }
};

int main(void)
{
    Solution obj;
    vector<string> arr = {"des", "der", "dfr", "dgt", "dfs"};

    string startWord = "der", targetWord = "dfs";
    int res = obj.wordLadderLength(startWord, targetWord, arr);
    cout << res << endl;
    return 0;
}