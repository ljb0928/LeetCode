#include <iostream> 
#include <vector> 
#include <unordered_map> 

using namespace std;


class Solution {
public:
    // Solution 1. O(n^2) time | O(1) space 
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) { 
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        
        return res;
    }
    
    // Solution 2. O(n) time | O(n) space 
    vector<int> twoSum2(vector<int>& nums, int target) {

        unordered_map<int, int> m;  // key = diff, value = idx of nums; 
        
        // Condition: nums[i] + nums[j] = target 
        // Condition: nums[j] = target - nums[i] = diff 
        
        for(int i=0; i<nums.size(); ++i) {
            int diff = target - nums[i]; 
            
            if (m.count(diff)) {    // m.count(diff) returns whether 'diff' key exists in m or not. 
                return {m[diff], i}; 
            }
            
            m[nums[i]] = i; // put index as value. 
        }

        return {} ;
    }
    // Hash table looks like this:
    // key, value
    // 2, 0 
    // 
    
    
};


int main() {
    
    // Example 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    
    // Example 2 
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    
    // Example 3 
    vector<int> nums3 = {3, 3};
    int target3 = 6; 

    vector<int> result; 

    Solution s;
    result = s.twoSum2(nums3, target3); 
    
    for(int i=0; i<result.size(); i++) {
        cout << "Output : " << result.at(i) << ", "; 
    }
    cout << endl; 



    return 0;
}


