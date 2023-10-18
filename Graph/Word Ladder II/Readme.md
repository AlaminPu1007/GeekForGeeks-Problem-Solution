## Word Ladder II

-   [Visit Problem on GeekForGeeks](https://practice.geeksforgeeks.org/problems/word-ladder-ii/1)
-   [Visit Problem on leetcode](https://leetcode.com/problems/word-ladder-ii/)

**Approach The Algorithm for this problem involves the following steps :**<br/>

-   Firstly, we start by creating a hash set to store all the elements present in the wordList which would make the search and delete operations faster for us to implement.
-   Next, we create a Queue data structure for storing the successive sequences/ path in the form of a vector which on transformation would lead us to the target word
-   Now, we add the startWord to the queue as a List and also push it into the usedOnLevel vector to denote that this word is currently being used for transformation in this particular level.
-   Pop the first element out of the queue and carry out the BFS traversal, where for each word that popped out from the back of the sequence present at the top of the queue, we check for all of its characters by replacing them with ‘a’ – ‘z’ if they are present in the wordList or not. In case a word is present in the wordList, we simply first push it onto the usedOnLevel vector and do not delete it from the wordList immediately
-   Now, push that word into the vector containing the previous sequence and add it to the queue. So we will get a new path, but we need to explore other paths as well, so pop the word out of the list to explore other paths.
-   After completion of traversal on a particular level, we can now delete all the words that were currently being used on that level from the usedOnLevel vector which ensures that these words won’t be used again in the future, as using them in the later stages will mean that it won’t be the shortest path anymore.
-   If at any point in time we find out that the last word in the sequence present at the top of the queue is equal to the target word, we simply push the sequence into the resultant vector if the resultant vector ‘ans’ is empty.
-   If the vector is not empty, we check if the current sequence length is equal to the first element added in the ans vector or not. This has to be checked because we need the shortest possible transformation sequences.
-   In case, there is no transformation sequence possible, we return an empty 2D vector.

**References :**<br/>

-   [From Article](https://takeuforward.org/graph/g-30-word-ladder-ii/)
-   [From Video](https://www.youtube.com/watch?v=DREutrv2XD0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=30)
