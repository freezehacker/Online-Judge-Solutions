#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;

        ListNode *pre;
        ListNode *post;
        int counter = 0;
        for ( ; counter < m - 1; ++counter ) {
            head = head->next;
        }
        pre = head;
        head = head->next;
        post = head;

        ListNode *last = NULL;
        ListNode *next;
        ListNode *temp = head;
        for (; head && counter < n; ++counter) {
            next = head->next;
            head->next = last;
            last = head;
            head = next;
        }

        // Concatenate the reversed list with the nodes left.
        pre->next = last;
        post->next = head;

        return dummy.next;
    }
};


int main() {
    return 0;
}
