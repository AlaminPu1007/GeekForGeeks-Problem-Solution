## City With the Smallest Number of Neighbors at a Threshold Distance

-   [Visit Problem](https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1)

**Approach :**<br/>
In order to solve this problem, we will use the Floyd Warshall algorithm (article link of Floyd Warshall). We know Floyd Warshall algorithm helps us to generate a 2D matrix, that stores the shortest distances from each node to every other node. In the generated 2D matrix, each cell matrix[i][j] represents the shortest distance from node i to node j.<br/>

-   [Learn Floyd Warshall algorithm](https://github.com/AlaminPu1007/GeekForGeeks-Problem-Solution/blob/main/Floyd%20Warshall/Readme.md)

**Complexity Analysis :**<br/>

-   Time Complexity: `O(V3)`, as we have three nested loops each running for V times, where V = no. of vertices.
-   Space Complexity: `O(V2)`, where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
