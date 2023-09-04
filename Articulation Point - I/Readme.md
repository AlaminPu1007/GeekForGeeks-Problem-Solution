## Articulation Point - I (Articulation Point in Graph)

This problem involved about, given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.

# Problem description

For better problem description, please visit [GeekForGeeks Pages](https://practice.geeksforgeeks.org/problems/articulation-point-1/1)

**Approach :**<br/>

-   [Learn approach from blog](https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/)

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(V+2E)`, where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
-   Space-Complexity: `O(3V)`, where V = no. of vertices. O(3V) is for the three arrays i.e. tin, low, and vis, each of size V.

**References :**<br/>

-   [Learn from video tutorial](https://www.youtube.com/watch?v=j1QDfU21iZk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=56)
-   [Learn from article](https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/)
