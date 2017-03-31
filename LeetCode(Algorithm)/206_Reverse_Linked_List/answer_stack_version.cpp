// 9ms
// space: O(n)
// time: O(n)

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> values;

        while ( head ) {
            values.push( head->val );
            head = head->next;
        }

        ListNode* list = NULL;
        ListNode** indir = &list;
        while ( !values.empty() ) {
            *indir = new ListNode( values.top() );
            indir = &( (*indir)->next );
            values.pop();
        }

        return list;
    }
};


int main(int argc, char const *argv[]) {
    
    return 0;
}