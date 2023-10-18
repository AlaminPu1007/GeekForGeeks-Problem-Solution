## Distance from the Source (Bellman-Ford Algorithm)

-   [Visit Problem](https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1)

**Approach :**<br/>

distance array(dist[ ]): The dist[] array will be initialized with infinity, except for the source node as dist[src] will be initialized to 0.<br/>

**The algorithm steps will be the following :** <br/>

-   First, we will initialize the source node in the distance array to 0 and the rest of the nodes to infinity.
-   Then we will run a loop for N-1 times.
-   Inside that loop, we will try to relax every given edge.
    For example, one of the given edge information is like (u, v, wt), where u = starting node of the edge, v = ending node, and wt = edge weight. For all edges like this we will be checking if node u is reachable and if the distance to reach v through u is less than the distance to v found until now(i.e. dist[u] and dist[u]+ wt < dist[v]).
-   After repeating the 3rd step for N-1 times, we will apply the same step one more time to check if the negative cycle exists. If we found further relaxation is possible, we will conclude the graph has a negative cycle and from this step, we will return a distance array of -1(i.e. minimization of distances is not possible).
-   Otherwise, we will return the distance array which contains all the minimized distances.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(V*E)`, where V = no. of vertices and E = no. of Edges.
-   Space-Complexity: `O(V)` for the distance array which stores the minimized distances.

**References :**<br/>

-   [Learn More better Approach from blog](https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/)
-   [Helpful video tutorial](https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=41)
