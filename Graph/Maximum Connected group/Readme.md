## Making a Large Island

This problem involved about, You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.
You can change at most one cell in grid from 0 to 1. You need to find the largest group of connected 1's. Two cells are said to be connected if both are adjacent to each other and both have same value.

# Problem description

For better explanation, please visit [GeekForGeeks page](https://practice.geeksforgeeks.org/problems/maximum-connected-group/1)

**Approach :**<br/>

The algorithm steps are as follows (step 3 is very important): <br/>

1. Our first objective is to connect all the nodes that have formed groups. In order to do so, we will visit each cell of the grid and check if it contains the value 1.
    - If the value is 1, we will check all four adjacent cells of the current cell. If we find any adjacent cell with the same value 1, we will perform the union(either unionBySize() or unionByRank()) of the two node numbers that represent those two cells i.e. the current cell and the adjacent cell.
    - Now, step 1 is completed.
2. Then, we will again visit each cell of the grid and check if it contains the value 0
    - If the value is 0, we will check all four adjacent cells of the current cell. If we found any cell with value 1, we will just insert the ultimate parent of that cell(using the findUPar() method) in the set data structure. This process will add the adjacent components to our answer.
    - After doing so for all the adjacent cells containing 1, we will iterate through the set data structure and add the size of each ultimate parent(referring to the size array inside the Disjoint Set data structure) to our answer. Finally, we will add an extra 1 to our answer for the current cell being included in the group.
    - Now, we will compare to get the maximum answer among all the previous answers we got for the previous cells with the value 0 and the current one
3. But if the matrix does not contain any cell with 0, step 2 will not be executed. For that reason, we will just run a loop from node number 0 to `n*n` and for each node number, we will find the ultimate parent. After that, we will find the sizes of those ultimate parents and will take the size of the largest one.
4. Thus we will get the maximum size of the group of connected 1s stored in our answer.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n^2)+O(n^2) ~ O(n^2)` where` n = total number of rows` of the grid. Inside those nested loops, all the operations are taking apparently constant time. So, `O(n^2)` for the nested loop only, is the time complexity.

-   Space-Complexity: `O(2 * n^2)` - where N = the total number of rows of the grid. This is for the two arrays i.e. parent array and size array of size N^2 inside the Disjoint set.
