#include <iostream>
#include <fstream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    	ListNode* newList = NULL;
    	ListNode* next;
        while ( head ) {
        	next = head->next;
        	insert( newList, head );
        	head = next;
        }
        return newList;
    }

    void insert(ListNode* &head, ListNode* curNode) {
    	ListNode** indirect = &head;
    	while ( *indirect && curNode->val >= (*indirect)->val ) {
    		indirect = &( (*indirect)->next );
    	}
    	curNode->next = *indirect;
    	*indirect = curNode;
    }
};

int main() {
	return 0;
}
