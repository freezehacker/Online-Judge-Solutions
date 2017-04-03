
/*
* Use a map to remember those who has been visited.
*/
#include <iostream>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map< ListNode*, bool > visited;

        for (; head; head = head->next) {
            if ( visited.count( head ) == 1 ) {
                return true;
            }
            visited[head] = true;
        }

        return false;
    }
};

