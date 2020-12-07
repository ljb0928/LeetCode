// 5. Longest Palindromic Substring
// Medium

/*
Given a sting s, return the longest palindromic substring in s. 

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer. 

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output = "a"
*/

#include <iostream>
#include <string> 
#include <vector> 

using namespace std; 


// Approach 2. Brute Force.
// Pick all possible starting and ending position for a substring, and verify if it is a palindrome.
// O(n^3) time | O(1) space - where n is the length of input string. 
// Time complexity: There are nC2 = n(n-1)/2 such substrings in a string of length n.
// Then, verifying each substring takes O(n) time. Thus, finally O(n^3). 

// Approach 3. Dynamic Programming. 
// Observe how we can avoid unnecessary recomputation while validating palindromes.
// Ex) "ababa" : We already know that "bab" is a palindrome. Then, "ababa" is also obviously a 
// palindrome since two left and right letters are the same. 
//
// def isPalindrome(i, j):
//   true, if the substring S_i ... S_j is a palindrome
//   false, otherwise
// 
// Therefore, 
// isPalindrome(i, j) = (isPalindrome(i+1, j-1) && S_i == S_j) 
// 
// The base cases are:
// P(i, i) = true
// P(i, i+1) = (S_i == S_(i+1))
// 
// This yields a straightforward DP solution. We first initialize the one and two letters palindromes,
// and work our way up finding all three letters palindromes, and so on... 
// 
// O(n^2) time | O(n^2) space 
// 
//  https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
//  https://www.youtube.com/watch?v=HBtiDHIOK9A&feature=emb_title

// Approach 4. Expand around center
// We see that a palindrome mirrors around its center. Thus, a palindrome can be expanded from its 
// center. There are 2n-1 such centers.
// O(n^2) time | O(1) space
// Expanding a palindrome around its center takes O(n) time. Thus, overall, O(n^2).
// https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
class Solution {
public:

  string longestPalindrome(string s) {
      
    string ans; 
    int n = s.length(); 
    int substrMaxLength, low, high = 0; 
    int left, right;
    
    for(int i=0; i<n; i++) {
     
      // 1) Odd length palindrome
      left = i; 
      right = i; 
      while(left >= 0 && right < s.length() && s[left]==s[right]) { // Check for palindrome 
        left--; 
        right++; 
      }
      if (right - left - 1 > substrMaxLength) {// Make sure the palindrome is the longest. 
        low = left + 1;
        high = right - 1; 
        substrMaxLength = right - left - 1; 
      }
      
      // 2) Even length palindrome 
      left = i; 
      right = i+1; 
      while(left >= 0 && right < s.length() && s[left]==s[right]) { // Check for palindrome
        left--;
        right++; 
      }
      if (right - left - 1 > substrMaxLength) { // Make sure the palindrome is the longest. 
        low = left + 1;
        high = right - 1;
        substrMaxLength = right - left - 1; 
      }

    }
    
    return ans = s.substr(low, high-low+1); 

  }
};



int main() {
  
  //string s = "babad"; 
  string s = "dbbd";

  Solution sol;
  string result; 

  result = sol.longestPalindrome(s); 

  cout << result << endl; 

  return 0; 
}


