// 13ms
// space: O(n)
// time: O(n)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ( !head ) return NULL;

        ListNode dummy(0);
        ListNode* ret = &dummy;

        postOrder( head, ret );

        return dummy.next;
    }

    void postOrder(ListNode* node, ListNode* &ret) {
        if ( node ) {
            postOrder( node->next, ret );

            ret->next = new ListNode( node->val );
            ret = ret->next;
        }
    }
};


int main(int argc, char const *argv[]) {
    
    return 0;
}