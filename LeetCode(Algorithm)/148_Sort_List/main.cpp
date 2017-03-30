#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        mergeSort( head );
        return head;
    }

private:
    void mergeSort(ListNode* &head) {
        if ( head && head->next ) { // If the list has elements over 1.
            ListNode* second_list = divide( head );
            mergeSort( head );
            mergeSort( second_list );
            head = merge( head, second_list );
        }
    }

    /* Return the head of the second list. */
    ListNode* divide(ListNode* list) {
        if ( !list ) return NULL;

        ListNode *p1, *p2;
        p1 = list;
        p2 = list->next;
        while ( p2 ) {
            p2 = p2->next;
            if ( p2 ) {
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        // Now p1 is the middle position.

        ListNode* ret = p1->next;
        p1->next = NULL;    // Cut into the first list.
        return ret;
    }

    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode dummy(0);
        ListNode* list = &dummy;
        while ( first && second ) {
            if ( first->val < second->val ) {
                list->next = first;
                first = first->next;
            } else {
                list->next = second;
                second = second->next;
            }
            list = list->next;
        }
        if ( first ) list->next = first;
        if ( second ) list->next = second;
        return dummy.next;
    }
};


int main() {
    return 0;
}
