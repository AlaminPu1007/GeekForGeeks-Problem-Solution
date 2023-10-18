## Maximum Stone Removal

This problem involved about, There are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have at most one stone. You need to remove some stones.

# Problem description

For better explanation of this problem, please visit [GeekForGeeks Page](https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1)

**Approach :**<br/>

1. First, from the stone information, we will find out the maximum row and the maximum column number so that we can get an idea about the size of the 2D plane(i.e. nothing but a matrix).
2. Then, we need to create a disjoint set of sizes (maximum row index+maximum column index). For safety, we may take a size one more than required.
3. Now it’s time to connect the cells having a stone. For that we will loop through the given cell information array and for each cell we will extract the row and the column number and do the following:
    - First, we will convert column no. to (column no. + maximum row index +1).
    - We will perform the union(either unionBySize() or unionByRank()) of the row number and the converted column number.
    - We will store the row and the converted column number in a map data structure for later use.
4. Now, it’s time to calculate the number of components and for that, we will count the number of ultimate parents. Here we will refer to the previously created map.
    - We just need the nodes in the Disjoint Set that are involved in having a stone. So we have stored the rows and the columns in a map in step 3.3, as they will have stones. Now we just need to check them from the map data structure once for getting the number of ultimate parents.
5. Finally, we will subtract the no. of components(i.e. no. of ultimate parents) from the total no. of stones and we will get our answer.

**Complexity Analysis :**<br/>

-   Time-Complexity: ` O(N)`, where `N` = total no. of stones. Here we have just traversed the given stones array several times. And inside those loops, every operation is apparently taking constant time. So, the time complexity is only the time of traversal of the array.
-   Space-Complexity: `O(2* (max row index + max column index))` for the parent and size array inside the Disjoint Set data structure.

**References :**<br/>

-   [Get helpful hand from video](https://www.youtube.com/watch?v=OwMNX8SPavM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=53)
-   [Get helpful hand from article](https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/)
