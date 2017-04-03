/*
#include <iostream>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* next=NULL) : val(x), next(next) {}
};
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( !head ) return false;

        ListNode *slow = head;
        ListNode *fast = head;
        do {
            
            // 'slow' walk 1 step every time.
            if ( slow ) slow = slow->next;

            // And 'fast' walk 2 steps each time.
            if ( fast ) fast = fast->next;
            if ( fast ) fast = fast->next;

            // Arriving at NULL(tail) means no cycle.
            if ( !fast ) return false;  

        } while (slow && fast && slow != fast);

        // When 'slow' and 'fast' meets, it means there's a cycle.
        return true;
    }
};

/*void destroyListPossiblyWithACycle(ListNode* &head) {
    map< ListNode*, bool > toDelete;

    while ( head ) {
        if ( toDelete.count( head ) == 1 ) {
            break;
        }
        toDelete[head] = true;
    }

    map< ListNode*, bool >::iterator iter = toDelete.begin();
    for (; iter != toDelete.end(); ++iter) {
        if ( iter->first ) {
            delete iter->first;
            //iter->first = NULL;
        }
    }
}


int main() {
    ListNode *head = new ListNode(1);
    
    ListNode *p = head;
    p->next = new ListNode(2);
    p = p->next;
    ListNode *cycleHead = p;

    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);    
    p->next->next = cycleHead; // Create a cycle.

    cout << ( Solution().hasCycle(head) ? "Cycle exists." : "Not cycle." ) << endl;


    destroyListPossiblyWithACycle(head);
    return 0;
}
*/