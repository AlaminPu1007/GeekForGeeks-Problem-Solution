## Alien Dictionary

[Visit Problem](https://practice.geeksforgeeks.org/problems/alien-dictionary/1)

**Approach :**<br/>

-   The algorithm steps are as follows:

1. First, we need to create the adjacency list for the graph. The steps are the following
    - We will run a loop from the starting index to the second last index because we will check the ith element and the (i+1)th element.
    - Inside the loop, we will pick two words (the word at the current index(s1) and the word at the next index(s2)). For comparing them, we will again run a loop up to the length of the smallest string.
    - Inside that second loop, if at any index we find inequality (s1[i] != s2[i]), we will add them to the adjacency list (s1[i] —> s2[i]) in terms of numbers(subtracting ‘a’ from them), and then we will immediately come out of the loop.
    - This is only because we want the first differentiating character. Finally, we will get the adjacency list.
    - In short, we need to find the differentiating character for adjacent strings and create the graph.
2. Once the graph is created, simply perform a topo sort, whose steps are given below.
3. Then, we will calculate the indegree of each node and store it in the indegree array. We can iterate through the given adj list, and simply for every node u->v, we can increase the indegree of v by 1 in the indegree array.
4. Initially, there will be always at least a single node whose indegree is 0. So, we will push the node(s) with indegree 0 into the queue.
5. Then, we will pop a node from the queue including the node in our answer array, and for all its adjacent nodes, we will decrease the indegree of that node by one. For example, if node u that has been popped out from the queue has an edge towards node v(u->v), we will decrease indegree[v] by 1.
6. After that, if for any node the indegree becomes 0, we will push that node again into the queue.
7. We will repeat steps 3 and 4 until the queue is completely empty. Finally, completing the BFS we will get the linear ordering of the nodes in the answer array.
8. For the final answer, we will iterate on the answer array and add each element in terms of character(adding ‘a’ to each of them) to the final string. Then we will return the string as our final answer.

**Complexity Analysis :**<br/>

-   Time Complexity: `O(N*len)+O(K+E)`, where N is the number of words in the dictionary, ‘len’ is the length up to the index where the first inequality occurs, `K = no. of nodes, and E = no`. of edges.
-   Space Complexity: `O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K)` for the indegree array, and `O(K)` for the queue data structure used in `BFS(where K = no.of nodes), O(K)` for the answer array and `O(K)` for the adjacency list used in the algorithm

**References :**<br/>

-   [From Article](https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/)
-   [From Video](https://www.youtube.com/watch?v=U3N_je7tWAs&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=26)

**Note :**<br/>

-   when the larger string is before the sort string and both have matching char, then the answer will be no always.

```
i)  abcd
ii) abc
```

-   when any cycle is present, then the answer also would be no

```
i)   abc
ii)  bat
iii) ade

EX: a < b < a
```
