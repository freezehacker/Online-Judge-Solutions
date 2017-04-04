#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        --n;

        ListNode* fast = head;
        ListNode** slow = &head;

        while ( n-- ) {
        	fast = fast->next;
        }

        while ( fast->next ) {
        	fast = fast->next;
        	slow = &( (*slow)->next );
        }

        ListNode *toDelete = *slow;
        *slow = (*slow)->next;
        delete toDelete;

        return head;
    }
};


int main() {
	return 0;
}