// 3. Longest Substring Without Repeating Characters
// Medium 

/*
Given a string s, find the length of the 'longest substring' without repeating characters. 

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: THe answer is "wke", with the length of 3. 
Notice that the answer must be a substring, "pwke" is a subsequence, not a substring. 

Example 4:
Input: s = ""
Output: 0
*/

#include <iostream> 
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
  int max(int a, int b) {
    return (a > b) ? a : b; 
  }
  
  int lengthOfLongestSubstring(string s) {
    // iterate through s.
    // Get the first character of s. Check if this first char exists in the set. 
    // If not found, insert into set. Else, erase from the set. 

    int left = 0; 
    int right = 0; 
    int max_length = 0; 
    set<char> myset; 

    while (right < s.size()) {
      if(!myset.count(s[right])) { 
        myset.insert(s[right]);
        right++;
        max_length = max(max_length, myset.size()); 
      } else {
        myset.erase(s[left]);
        left++;
      }
    }
    
    // for(auto i:myset) { 
    //   cout << i << endl; 
    // }

  return max_length;
  }
  

};

int main() {
    
  string s1 = "abcabcbb";
  int ans1 = 3;

  string s2 = "bbbbb";
  int ans2 = 1;

  string s3 = "pwwkew";
  int ans3 = 3;

  string s4 = "";
  int ans4 = 0;

  int result1, result2, result3, result4;

  Solution s;
  result1 = s.lengthOfLongestSubstring(s1);
  result2 = s.lengthOfLongestSubstring(s2);
  result3 = s.lengthOfLongestSubstring(s3);
  result4 = s.lengthOfLongestSubstring(s4);

  // cout << s1 << endl;
  cout << result1 << endl;
  cout << result2 << endl;
  cout << result3 << endl;
  cout << result4 << endl;

  

  assert(result1 == ans1);
  assert(result2 == ans2);
  assert(result3 == ans3);
  assert(result4 == ans4);

  return 0;
}


