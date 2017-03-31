#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
    	// 'node->next' is NOT null, according to the description.
    	
    	ListNode* entry = node->next;   // The 'old' next node.

        node->val = node->next->val;	// Get the value of next node.
        node->next = node->next->next;	// Get the next address of next node.

        delete entry;	// Can delete the old node now.
    }
};