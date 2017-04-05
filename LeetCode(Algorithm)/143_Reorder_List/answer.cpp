#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if ( !head || !head->next ) return;

        ListNode *slow = head;
        ListNode *fast = head;
        while ( fast && fast->next && fast->next->next ) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Divide into 2 sublists.
        ListNode *secondHead = slow->next;
        slow->next = NULL;

        // Reverse the second one.
        reverseList( secondHead );

        // Merge 2 sublists.
        ListNode dummy(0);
        ListNode *newList = &dummy;
        ListNode *next;
        while ( true ) {
            if ( head ) {
                next = head->next;
                newList->next = head;
                newList = newList->next;
                head = next;
            } else {
                newList->next = secondHead;
                break;
            }

            if ( secondHead ) {
                next = secondHead->next;
                newList->next = secondHead;
                newList = newList->next;
                secondHead = next;
            } else {
                newList->next = head;
                break;
            }
        }
    }

    void reverseList(ListNode* &head) {
        ListNode *next, *last = NULL;
        while ( head ) {
            next = head->next;
            head->next = last;
            last = head;
            head = next;
        }

        head = last;
    }
};


int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}