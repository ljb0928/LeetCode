# LeetCode
LeetCode Practice

```
1_TwoSum: Use one-pass Hash table.
```

```
2_AddTwoNumbers: Use Linked List, and construct it. 
```

```
3_LongestSubstringWIthoutRepeatingCharacters: Two pointer technique. 
L and R. Use Set because "non-repetitive characters, meaning unique" characters. 
You can only insert an element into set if it's unique. Slide through the given 
string with L and R ptrs, and insert into set if s[right] is unique. 
Else, erase. Keep updating the set size as the answer. 
```

```
21_MergeTwoSortedLists: Use Linked List. 
As you traverse the LL iteratively, modify the two LLs by linking into a single list. 
```

```
42_TrappingRainWater: Gotta find a formula / method / pattern solve optimally. 
2 pointer technique. 
``` 

```
5_LongestPalindromicSubstring: Two pointer technique. Linear scan a string to pick a center, 
and expand from the center. 
```

```
62_UniquePaths: Recursion. Or, standard dynamic programming problem using systolic array style. 
```

``` 
146_LRUCache: Hash table + LL. Typical Linked List for Caching. 
But, Hash map is used to improve efficiency - O(1) lookup
```

``` 
200_NumberOfIslands: Typical 2D grid search problem. DFS or BFS. Recursion or Iteration.
```

```
937_ReorderDataInLogFiles: ... gotta use the sort (thumb down) 
```

```
980_UniquePathsIII (robot vacuum)
Use DFS to traverse. 
cntEmpty is the key to make sure to traverse all empty nodes. 
Do DFS into 4 directions, and when you reach the end of DFS, increment the answer. 
```

