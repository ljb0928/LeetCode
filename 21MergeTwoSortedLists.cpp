#include <iostream>

using namespace std; 

/**
 * Definition for singly-linked list. */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 
 /*
 Example 
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4 
 */
// My solution: Iteration 
// O(n+m) time | O(n+m) space - where n and m are lengths of list 1 and 2, each.
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyRoot = new ListNode(-1); 
        ListNode* ptr_ans = dummyRoot; 
        ListNode* ptrl1 = l1; 
        ListNode* ptrl2 = l2; 
        
        // Traverse both lists. 
        while(ptrl1 != nullptr && ptrl2 != nullptr) {
            if (ptrl1->val < ptrl2->val) {
                // Create a new node with smaller value
                ptr_ans->next = new ListNode(ptrl1->val); 
                // Increment ptrs 
                ptr_ans = ptr_ans->next; 
                if(ptrl1 != nullptr) ptrl1 = ptrl1->next; 
            }
            else {
                // Create a new node with smaller value 
                ptr_ans->next = new ListNode(ptrl2->val); 
                // Increment ptrs 
                ptr_ans = ptr_ans->next; 
                if(ptrl2 != nullptr) ptrl2 = ptrl2->next; 
            }
        }
        
        // Store remaining elements of first list
        while (ptrl1 != nullptr) { 
            ptr_ans->next = new ListNode(ptrl1->val); 
            ptr_ans = ptr_ans->next;
            if(ptrl1 != nullptr) ptrl1 = ptrl1->next; 
        }

        // Store remaining elemtns of secodn list 
        while (ptrl2 != nullptr) { 
            ptr_ans->next = new ListNode(ptrl2->val);
            ptr_ans = ptr_ans->next;
            if(ptrl2 != nullptr) ptrl2 = ptrl2->next; 
        }        
            
        return dummyRoot->next; 
    }
};


// Approach 2: Iteration without memory instantiation 
// O(m+n) time | O(1) space 
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *prehead = new ListNode(-1); // Only used for once at the beginnig.
        
        ListNode *prev = prehead; // Actual ptr to determine min val btn the two lists. 
        
        while (l1 != nullptr && l2 != nullptr) { 
            
            if (l1->val <= l2->val) {
                prev->next = l1; 
                l1 = l1->next; // Advance l1 only in this case. 
            } 
            else {
                prev->next = l2;
                l2 = l2->next; // Advance l2 only in this case. 
            }
            
            prev = prev->next; // Advance prev anyway 
        }
        
        // exactly one of l1 and l2 can be non-null at this point. Thus connect. 
        // the non-null list goes to the end of the merged list. 
        prev->next = (l1 == nullptr) ? l2 : l1; 
        
        return prehead->next; 
    }
}; 


void print_LL(ListNode *node) {
    while(node != nullptr) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << endl;
}

 /*
 Example 
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4 
 */
int main () {
    ListNode *l1_3 = new ListNode(4);
    ListNode *l1_2 = new ListNode(2, l1_3);
    ListNode *l1_1 = new ListNode(1, l1_2); 
    cout << "List1: ";
    print_LL(l1_1);
    
    ListNode *l2_3 = new ListNode(4);
    ListNode *l2_2 = new ListNode(3, l2_3);
    ListNode *l2_1 = new ListNode(1, l2_2); 
    cout << "List2: "; 
    print_LL(l2_1); 
    
    Solution2 s;
    ListNode *result;
    result = s.mergeTwoLists(l1_1, l2_1); 
    print_LL(result); 
    
    return 0;
}
