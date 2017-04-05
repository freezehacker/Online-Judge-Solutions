/*
*
*   This answer is based on rotation from the right(tail). For example:
*   Original list: 1-2-3-4-5
*   1 step: 5-1-2-3-4
*   2 steps: 4-5-1-2-3
*   ...
*   
*   And this answer is what LeetCode 61 wants.
*
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
        ListNode *tmp = head;
        int size = 0;
        for ( ; tmp; tmp = tmp->next ) {
            ++size;
        }
        k %= size;


        // Rotate k times.
        while ( k-- ) {
            ListNode *tail = head;
            while ( tail->next->next ) {    // 'tail' goes to the second last node.
                tail = tail->next;
            }

            ListNode *toRotate = tail->next;

            tail->next = NULL;  // Cut.
            toRotate->next = head;  // Concatenate.

            head = toRotate;    // Keep the 'head' pointing to the head of the list.
        }

        // Return the head of the list.
        return head;
    }
};


int main() {
    return 0;
}