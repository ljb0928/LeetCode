#include <iostream>
#include <vector>
#include <assert.h> 
#include <algorithm> 

using namespace std;


class Solution {
public:
//    int trap(vector<int>& height) {
//        
//        int ans = 0; 
//        int n = height.size(); 
//
//        // Iterate through the whole array 
//        for(vector<int>::iterator it = height.begin(); it != height.end(); advance(it,1)) {
//
//            // Identify left_max. Go leftward. 
//            int left_max = 0;
//            left_max = *max_element(height.begin(), next(it,1));
//            
//            // Identify right_max. Go rightward. 
//            int right_max = 0; 
//            right_max = *max_element(it, height.end()); 
//
//            // Calculate amount of trapped water at i and accumulate it to ans. 
//            ans += min(left_max, right_max) - *it;
//        }
//        
//        return ans;
//    }
    int trap(vector<int>& height) {
        
        int ans = 0; 
        int n = height.size(); 

        // Iterate through the whole array 
        for(vector<int>::iterator it = height.begin(); it != height.end(); advance(it,1)) {

            // Identify left_max. Go leftward. 
            int left_max = 0;
            left_max = *max_element(height.begin(), next(it,1));
            
            // Identify right_max. Go rightward. 
            int right_max = 0; 
            right_max = *max_element(it, height.end()); 

            // Calculate amount of trapped water at i and accumulate it to ans. 
            ans += min(left_max, right_max) - *it;
        }
        
        return ans;
    }

};


int main() {
    
    Solution s;
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1}; 
    int result;
    result = s.trap(input);
    cout << "result: " << result << endl;
    
    //assert(result == 6); 
    
    return 0;
}
