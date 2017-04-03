/*
* Bad, because the method changes the whole list.
* 
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while ( head ) {
            if ( head->val == 0x3f3f3f3f ) {
                return true;
            } else {
                head->val = 0x3f3f3f3f;
            }
            head = head->next;
        }
        return false;
    }
};