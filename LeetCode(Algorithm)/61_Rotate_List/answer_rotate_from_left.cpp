/*
*   This answer is based on rotation from the left(head). For example:
*   Original list: 1-2-3-4-5
*   1 step: 2-3-4-5-1
*   2 steps: 3-4-5-1-2
*   ...
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Special case: list with 0 or 1 node.
        if ( !head || !head->next ) return head;

        // Deal with a possibly large 'K'
        ListNode *tail = head;
        int size = 1;
        for ( ; tail->next; tail = tail->next ) {
            ++size;
        }
        k %= size;

        // Rotate k times.
        while ( k-- ) {
            ListNode *next = head->next;

            head->next = NULL;  // Cut.
            tail->next = head;  // Concatenate.

            // Go forward.
            head = next;
            tail = tail->next;
        }

        return head;
    }
};


int main() {
    return 0;
}