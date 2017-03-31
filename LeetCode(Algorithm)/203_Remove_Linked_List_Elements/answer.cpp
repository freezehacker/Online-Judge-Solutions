#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* toDelete;
        ListNode** indir = &head;
        while ( *indir ) {
        	if ( (*indir)->val == val ) {
        		toDelete = *indir;
        		*indir = (*indir)->next;
        		delete toDelete;
        	} else { 
        		indir = &( (*indir)->next );
        	}
        }
        return head;
    }
};

int main() {
	return 0;
}