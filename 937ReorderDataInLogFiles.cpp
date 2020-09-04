#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isDigitLog(string str) {
        int idx = str.find(' ');
        return isdigit(str[idx + 1]);
    }
    
    // N: size of vector
    // M: size of string 
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digit_log; // O(N) space 
        vector<string> letter_log; // O(N) space 
        
        for(auto s : logs) {
           if( isDigitLog(s) )
               digit_log.push_back(s);
           else
               letter_log.push_back(s);   
        } // O(N) time 
        
        sort( letter_log.begin(), letter_log.end(), 
            [] (string a, string b) {
                int idx1 = a.find(' '); // O(M) time & space
                int idx2 = b.find(' '); // O(M) time & space 

                return a.substr(idx1 + 1) <= b.substr(idx2 + 1);
            }
        ); // Sort: O(M log M) time | O(log M) space

        // Total: O(N * M logM) time for sort and find 
        // O(N * logM) space for sort. Sort function does mem allocation of object to be sorted. 

        // Concatenate letter_log and digit_log as a final answer. 
        letter_log.insert(letter_log.end(), digit_log.begin(), digit_log.end()); // O(1) 
        
        return letter_log;
    }
};


int main() {
    vector<string> input = {
        "dig1 8 1 5 1", 
        "let1 art can", 
        "dig2 3 6", 
        "let2 own kit dig", 
        "let3 art zero"
    };
    
    vector<string> result; 
    
    Solution s; 
    result = s.reorderLogFiles(input);
    
    for(auto s : result)
        cout << s << " "; 
    cout << endl;
    
    return 0;
}
