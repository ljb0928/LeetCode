#include <iostream>
#include <vector>
#include <assert.h> 

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) { 
        int width = grid[0].size(); 
        int height = grid.size(); 
        
        // Base case: End condition of searching
        if (i < 0 || i >= height || j < 0 || j >= width || grid[i][j] == '0') {  // i,j index out of grid scope || node is 0 
            cout << "Ending DFS." << endl; 
            return; 
        } 
        
        // Action: Searching 
        cout << "Mark the visited node as 0, and search in 4 directions" << endl; 
        grid[i][j] = '0'; // Mark the visited node as 0. 
        dfs(grid, i - 1, j); // downward
        dfs(grid, i + 1, j); // upward
        dfs(grid, i, j - 1); // leftward 
        dfs(grid, i, j + 1); // rightward 
    }
    
    // O(M*N) time | O(M*N) space, where M = width, N = height. 
    int numIslands(vector<vector<char>>& grid) { 
                
        // Corner case handling where grid is empty. 
        int height = grid.size();
        if (height == 0) return 0;
        
        int width = grid[0].size();
        if (width == 0) return 0; 
        
        int numIslands = 0; 
        
        // Linear scan the whole 2D grid. 
        for(int i=0; i<height; i++) { 
            for(int j=0; j<width; j++) { 
                if (grid[i][j] == '1') { 
                    numIslands++;       // Found the first '1' of an island. 
                    dfs(grid, i, j);    // Then, nullify all the '1's of this island. i.e. set to 0. 
                }
            }
        } 
        return numIslands; 
    }
    
}; 


int main() {
    // Example 1
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    int result1;
    
    // Example 2 
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'}, 
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'} 
    };
    int result2; 
    
    Solution s;
    result1 = s.numIslands(grid1); 
    result2 = s.numIslands(grid2); 
    
    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl; 
    
    assert(result1 == 1);
    assert(result2 == 3); 
    
    return 0;
}