// 980. Unique Paths III - vacuum robot problem 
// Hard

/*
On a 2-d grid, there are 4 types of squares:
- 1 represents the 'starting' square. There is only one starting square. 
- 2 represents the 'ending' square. There is only one ending square. 
- 0 represents 'empty' squares that we can walk over. 
- -1 represents 'obstacles' that we cannot walk over. 

Return the "number of 4-directional walks" from the starting square to the ending square, 
that 'walk over non-onbstacle square exactly once'. 
=> It's not the shortest path from start to end. Must traverse all nodes exactly once. 
*/


/*
Example 1: 
Input: [[ 1, 0, 0, 0],
        [ 0, 0, 0, 0],
        [ 0, 0, 2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0) (0,1) (0,2) (0,3) (1,3) (1,2) (1,1) (1,0) (2,0) (2,1) (2,2) 
2. (0,0) (1,0) (2,0) (2,1) (1,1) (0,1) (0,2) (0,3) (1,3) (1,2) (2,2) 

Example 2:
Input: [[ 1, 0, 0, 0],
        [ 0, 0, 0, 0], 
        [ 0, 0, 0, 2]]
Output: 4 
Explanation: We have the following four paths:
1. (0,0) (0,1) (0,2) (0,3) (1,3) (1,2) (1,1) (1,0) (2,0) (2,1) (2,2) (2,3) 
2. (0,0) (0,1) (1,1) (1,0) (2,0) (2,1) (2,2) (1,2) (0,2) (0,3) (1,3) (2,3) 
3. (0,0) (1,0) (2,0) (2,1) (2,2) (1,2) (1,1) (0,1) (0,2) (0,3) (1,3) (2,3) 
4. (0,0) (1,0) (2,0) (2,1) (1,1) (0,1) (0,2) (0,3) (1,3) (1,2) (2,2) (2,3) 

Example 3:
Input: [[0,1],
        [2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
*/


/*
Insight: Grid traversal? => DFS! This is a canonical "robot vacuum cleaner problem". 
Backtracking! State machine! 
Initial state:
  - There are different types of nodes in a grid. 
  - There are an origin and a destination cell.
  - Initially, all nodes are not visited. 
Final state:
  - Reach the dest cell, 2. 
  - Visited all non-obstacle cells, including initial (1) and empty cells (0). 

Pseudocode:
  def backtrack(cell):
    1. if we arrive at the final state:
      path_count++
      return 
    2. mark the current cell as visited
    3. for next_cell in 4 directions:
      if next_cell is not visited and non-obstacle:
        backtrack(next_cell)
    4. unmark the current cell 

Algorithm:
  Backtracking is a methodology to solve a specific type of problems. 
  For a backtracking problem, there might be a thousand backtracking implementations... 
  - In-place Modification
    - Important! Allows us to save some space in the algorithm.
    - To mark a node 'visited', use some matrix or hash table with boolean values to keep track of the state.
    - Simply assign a 'specific' value to the cell, rather than creating an additional matrix or hash table. 

  - Boundary Check
    - Check if a node is 'valid' or not, and if a node is 'visited' or not. 
    - Do the boundary check 'before' we do recursive call.
    - This can save some recursive calls. 

*/

#include <iostream> 
#include <vector>


using namespace std;

class Solution {
public:

  // This DFS function returns number of valid paths while recursively calling DFS function. 
  // Thus, counting numPaths while DFS-ing. 
  int dfs(vector<vector<int>>& grid, int i, int j, int cntEmpty) { 
    int width = grid[0].size();
    int height = grid.size(); 
    int numPaths = 0; // ans to return! 

    // Check the boundary and see if we are dfs-ing into valid path. 
    if ( i<0 || i>=height || j<0 || j>=width || grid[i][j] == -1 ) // out of range or visited already
      return 0; // Not incrementing numPaths. 

    // Ending condition of recursion: Check if we reached the end AND we visited all nodes. 
    if (grid[i][j] == 2) 
      return (cntEmpty == -1) ? 1 : 0; // By the time we reach 'end', cntEmpty is negative. 
      // Then, we return 1 to increment numPaths to indicate that a path is found. 

    // Action: Searching! 
    grid[i][j] = -1;  // Mark the visited node as -1.   
    cntEmpty--; 
    numPaths += dfs(grid, i, j + 1, cntEmpty); // rightward
    numPaths += dfs(grid, i + 1, j, cntEmpty); // upward
    numPaths += dfs(grid, i, j - 1, cntEmpty); // leftward
    numPaths += dfs(grid, i - 1, j, cntEmpty); // downward 

    // We have to try other paths as well. So, do backtracking. 
    grid[i][j] = 0; // backtrack to 0. 
    cntEmpty++; 

    return numPaths; 
  }




  int uniquePathsIII(vector<vector<int>>& grid) {
    
    int cntEmpty = 0; // number of empty nodes
    int numPaths = 0; // number of 4-directional paths from start to end. The answer of this question. 
    int numRow = grid.size();     // height
    int numCol = grid[0].size();  // width

    int row, col = 0; 

    // First, linear-scan the grid, and get info. 
    for (int i=0; i<numRow; i++) {
      for (int j=0; j<numCol; j++) {
        if (grid[i][j] == 1) { // Find the starting point. 
          row = i;
          col = j;
        }
        else if (grid[i][j] == 0)
          cntEmpty++;   // Count the number of empty nodes. 
      }
    }

    // Do the search. 
    numPaths = dfs(grid, row, col, cntEmpty); // Do DFS on the grid. 

    return numPaths; 

  }

};


int main () {

  vector<vector<int>> grid1 = {{ 1, 0, 0, 0},
                               { 0, 0, 0, 0},
                               { 0, 0, 2,-1}}; 

  Solution s;
  int result1;
  result1 = s.uniquePathsIII(grid1);


  cout << result1 << endl;

  return 0;
}







