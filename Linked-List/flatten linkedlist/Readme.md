## Flattening a Linked List

This problem involved about, given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:<br/>
(i) a next pointer to the next node,<br/>
(ii) a bottom pointer to a linked list where this node is head.

# Problem description

For better problem description, please visit [LeetCode Page](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1)

**Approach :**<br/>
The process to flatten the given linked list is as follows:-

1. We will recurse until the head pointer moves null. The main motive is to merge each list from the last.
2. Merge each list chosen using the merge algorithm. The steps are
3. Create a dummy node. Point two pointers, i.e, temp and res on dummy node. res is to keep track of dummy node and temp pointer is to move ahead as we build the flattened list.
4. We iterate through the two chosen. Move head from any of the chosen lists ahead whose current pointed node is smaller.
5. Return the new flattened list found.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n)` - `O(N)`, where N is the total number of nodes present
-   Space-Complexity: `O(1)`
