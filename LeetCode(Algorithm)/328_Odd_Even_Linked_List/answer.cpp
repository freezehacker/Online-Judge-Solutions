/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if ( !head ) return NULL;

        ListNode *odd_head = head;
        ListNode even_dummy(0); // For convenience.

        ListNode *odd = odd_head, *even = &even_dummy;

        while ( true ) {

            // Firstly check if 'odd->next' is null.
            if ( odd->next ) {
                even->next = odd->next;
                even = even->next;
            } else {
                even->next = NULL;  // Mark end.(Or a cycle will appear.)
                break;
            }

            // Then check 'even->next', in the same way.
            if ( even->next ) {
                odd->next = even->next;
                odd = odd->next;
            } else {
                odd->next = NULL;
                break;
            }
        }
        
        odd->next = even_dummy.next;    // Merge the two list.

        return odd_head;    // Return the head node of the list.
    }
};