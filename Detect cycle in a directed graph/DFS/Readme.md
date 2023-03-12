## Detect cycle in a directed graph

[Visit Problem](https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

**Complexity Analysis :**<br/>

-   Time Complexity: `O(V+E)+O(V)` , where `V = no. of nodes and E = no. of edges`. There can be at most V components. So, another `O(V)` time complexity.

-   Space Complexity: `O(2N) + O(N) ~ O(2N): O(2N)` for two visited arrays and `O(N)` for recursive stack space.

**References :**<br/>

-   [From Article](https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/)
-   [Video Description](https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=19)
