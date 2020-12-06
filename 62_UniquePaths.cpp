// 62. Unique Paths (Nothing blocking) 
// Medium

/*
A robot is located at the top-left corner of a m x n grid. A start node. 
Robot can either move down or right at any point in time. Robot is trying to reach the bottom-right
corner of the grid. 
How many possible unique paths are there? 
*/

/*
Note: m is the number of columns or height, n is the number of rows or width. (MATLAB style) 


Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are 3 ways in total to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Example 3:
Input: m = 7, n = 3
Output: 28

Example 4:
Input: m = 3, n = 3
Output: 6 
*/

#include <iostream>
#include <vector> 

using namespace std; 

class Solution {
public:
    
    // Solution 1. Naive brute force solution using "recursion". 
    // Recursion O(m*n) time | O(m*n) space 
    int uniquePaths1(int m, int n) { 
      // Ending condition. Reached the bottom-right end. 
      if (m==1 || n==1) { 
        return 1;
      } 
      return uniquePaths1(m-1, n) + uniquePaths1(m, n-1); // right + down 
    } 


    // Solution 2. "Dynamic Programming". Very standard DP Systolic Array problem. 
    // O(m*n) time | O(m*n) space. 
    int uniquePaths2(int m, int n) {

      vector<vector<int>> dp(m, vector<int>(n,0)); // Fill dp with all zeros. (both 1D and 2D) (m and n wise)
      dp[0][0] = 1; // Actually, this value doesn't matter... 

      // Fill the first column with 1's
      for(int i=0; i<m; i++)
        dp[i][0] = 1;
      // Fill the first row with 1's
      for(int j=0; j<n; j++)
        dp[0][j] = 1; 

      // Fill in the DP table - like a systolic array. 
      for(int i=1; i < m; i++) {
        for(int j = 1; j < n; j++) {
          dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
        }
      }
      return dp[m-1][n-1]; 
    }

};




int main () {
  
  int m = 7;
  int n = 3; 

  Solution s;
  int result = 0; 
  result = s.uniquePaths2(m, n); 

  cout << result << endl;

  return 0; 
}