// Use pointer-to-pointer.

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
        if ( !head || !head->next ) return head;


        ListNode *tmp = head;
        int size = 0;
        for ( ; tmp; tmp = tmp->next ) {
            ++size;
        }
        k %= size;


        // Rotate k times.
        while ( k-- ) {
            ListNode **tail = &head;
            while ( (*tail)->next ) {
                tail = &( (*tail)->next );
            }

            (*tail)->next = head;  // Concatenate.
            head = *tail;
            *tail = NULL;  // Cut.
        }


        // Return the head of the list.
        return head;
    }
};


int main() {
    return 0;
}