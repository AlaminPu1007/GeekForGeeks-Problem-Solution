// Time Limit Exceeded -> on leetcode
//  but accepted on geek-for-geeks
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int len = wordList.size();
        vector<vector<string>> ans;

        // define set and put wordList
        unordered_set<string> st(wordList.begin(), wordList.end());

        // define an queue which store list of path
        queue<vector<string>> q;
        q.push({beginWord});
        // define an use-vector to hold used word
        vector<string> useOnLevel;
        useOnLevel.push_back(beginWord);

        // define BFS level
        int level = 0;

        while (!q.empty())
        {
            vector<string> path = q.front();
            q.pop();

            // removed item from set, after completed it's level from queue
            if (path.size() > level)
            {
                string lastWord = useOnLevel.back();
                for (auto item : useOnLevel)
                    if (st.find(item) != st.end())
                        st.erase(item);

                // clear vector after successfully removed it from set
                useOnLevel.clear();
                level++;
            }

            // get last word from path
            string word = path.back();

            // push result in ans vector
            if (word == endWord)
            {
                if (!ans.size())
                    ans.push_back(path);
                else if (ans[0].size() == path.size())
                    ans.push_back(path);
                else if (ans[0].size() < path.size())
                    break;
            }

            //   for(auto item: path)
            //     cout<<item<<" ";
            // cout<<endl;

            for (int i = 0; i < word.size(); i++)
            {
                char originalChar = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    /*
                    C++ set count() function is used to return the number of elements found in the container. Since, the set container does not contain any duplicate element, this function actually returns 1 if the element with value val is present in the set container or 0 otherwise.
                    */
                    if (st.count(word))
                    {
                        path.push_back(word);
                        useOnLevel.push_back(word);

                        // insert into queue
                        q.push(path);

                        // removed item after push from path,
                        // cause it's bear an duplicate value
                        path.pop_back();
                    }
                }
                word[i] = originalChar;
            }
        }

        return ans;
    }
};

int main(void)
{
    Solution obj;

    vector<string> wordList = {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};

    string startWord = "qa", targetWord = "sq";

    vector<vector<string>> ans = obj.findLadders(startWord, targetWord, wordList);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}