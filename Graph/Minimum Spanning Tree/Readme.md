## Minimum Spanning Tree

-   [Visit Problem](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)

**Approach :**<br/>
**Intuition :**<br/>

The intuition of this algorithm is the greedy technique used for every node. If we carefully observe, for every node, we are greedily selecting its unvisited adjacent node with the minimum edge weight(as the priority queue here is a min-heap and the topmost element is the node with the minimum edge weight). Doing so for every node, we can get the sum of all the edge weights of the minimum spanning tree and the spanning tree itself(if we wish to) as well.

-   We will first push edge weight 0, node value 0, and parent -1 as a triplet into the priority queue to start the algorithm.
-   Then the top-most element (element with minimum edge weight as it is the min-heap we are using) of the priority queue is popped out.
-   After that, we will check whether the popped-out node is visited or not.
    If the node is visited: We will continue to the next element of the priority queue.
    If the node is not visited: We will mark the node visited in the visited array and add the edge weight to the sum variable. If we wish to store the mst, we should insert the parent node and the current node into the mst array as a pair in this step.
-   Now, we will iterate on all the unvisited adjacent nodes of the current node and will store each of their information in the specified triplet format i.e. (edge weight, node value, and parent node) in the priority queue.
-   We will repeat steps 2, 3, and 4 using a loop until the priority queue becomes empty.
-   Finally, the sum variable should store the sum of all the edge weights of the minimum spanning tree.

**Complexity Analysis :**<br/>

-   Time Complexity: `O(E*logE) + O(E*logE)~ O(E*logE)`, where E = no. of given edges.
-   Space-Complexity : `O(E) + O(V)`, where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.

**References :**<br/>

-   [Learn from article](https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/)
-   [Learn from video](https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=45)
