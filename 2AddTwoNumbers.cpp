#include <iostream>
using namespace std;
/*
Definition of singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 


/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) 
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807. 

Input: (2 -> 4) + (5 -> 6 -> 4) 
Output: (7 -> 0 -> 5)
Explanation: 42 + 465 = 507
*/


// O(max(m,n)) time | O(max(m,n)) space - where m and n are lengths of singly linked list 1 and 2. 
// l1 -> 2 -> 4 -> 3
// l2 -> 5 -> 6 -> 4
// ans, prev 
/*
Initialize current node to dummy head of the returning list. 
Initialize carry to 0. 
Initialize pp and qq to head of l1 and l2 respectively.
Loop through lists l1 and l2 until you reach both ends.
Set xx to node pp's value. If pp has reached the end of l1, set to 00.
Set yy to node qq's value. If qq has reached the end of l2, set to 00. 
Set sum = x + y + carry. 
Update carry = sum / 10.
Create a new node with the digit value of (sum mode 10) and set it to current node's next, then advance current node to next. 
Advane both pp and qq.
Check if carry = 1, if so append a new node with digit l1 to the returning list.
Return dummy head's next node. 
*/



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *dummyRoot = new ListNode(-1); // Create a dummyRoot with val of -1 initially. 
        ListNode *ptrans = dummyRoot; // Ptr to answer, which will be used to keep constructing answer LL. 
        ListNode *ptrl1 = l1; // Ptr to l1, which will be used to keep traversing l1.
        ListNode *ptrl2 = l2; // Ptr to l2, which will be used to keep traversing l2. 
        int carry = 0; // Initialize the carry to 0. Declared outside the while loop so that it can be carried over the loop. Carry will be updated after calculating sum, so that this variable can be again used as a carry in the next while loop iteration. 

        while(ptrl1 != nullptr || ptrl2 != nullptr) { // We keep traversing all valid l1 and l2 nodes. 
            
            //First, Fetch digit each from l1 and l2. Add condition to check if the node is valid. Else, get 0. 
            int x = (ptrl1 != nullptr) ? ptrl1->val : 0;
            int y = (ptrl2 != nullptr) ? ptrl2->val : 0; 
            
            // Then, calculate the sum, digit, carry. 
            int sum = carry + x + y; // Previous carry is used to sum the currentNode. Thus, carry is "carried over." "
    
            int digit = sum % 10; 
            carry = sum / 10; // Then, update the carry so that this carry can be used to calculate sum in the next iteration. 
            
            // Then, construct a new node and link it! 
            ptrans->next = new ListNode(digit); 
            
            // Then, proceed the ptr to l1, l2, and ans. 
            ptrans = ptrans->next; 
            if(ptrl1 != nullptr) ptrl1 = ptrl1->next;
            if(ptrl2 != nullptr) ptrl2 = ptrl2->next;
        }
    
        // After the iteration, there can be a node with carry only. 
        // Ex) 999 + 999 = 1998
        if (carry > 0)
            ptrans->next = new ListNode(carry); 
            
        return dummyRoot->next; // dummyRoot is used only to return the pointer to the answer linked list. Not used for algorithmic calculation purpose. 
    }
};


void print_LL(ListNode *node) {
    while(node != nullptr) {
        cout << node->val << " -> " ;
        node = node->next;
    }
    cout << endl;
}


int main() {
    
    ListNode *l1_3 = new ListNode(3); 
    ListNode *l1_2 = new ListNode(4, l1_3);
    ListNode *l1_1 = new ListNode(2, l1_2);
    cout << "LL1: ";
    print_LL(l1_1);
    
    ListNode *l2_3 = new ListNode(4); 
    ListNode *l2_2 = new ListNode(6, l2_3); 
    ListNode *l2_1 = new ListNode(5, l2_2);
    cout << "LL2: ";
    print_LL(l2_1);


    Solution s; 
    ListNode *result; 
    result = s.addTwoNumbers(l1_1, l2_1); 
    print_LL(result); 
       
    return 0; 
}
