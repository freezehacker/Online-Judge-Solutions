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
    ListNode *detectCycle(ListNode *head) {
        map< ListNode*, bool > visited;

        for (; head; head = head->next) {
        	if ( visited[head] ) return head;
        	visited[head] = true;

        }

        return NULL;
    }
};