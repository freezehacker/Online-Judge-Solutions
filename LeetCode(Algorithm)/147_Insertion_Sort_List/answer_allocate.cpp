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
        while ( head ) {
        	insert( newList, head->val );
        	head = head->next;
        }
        return newList;
    }

    void insert(ListNode* &head, int newVal) {
    	ListNode** indirect = &head;
    	while ( *indirect && newVal >= (*indirect)->val ) {
    		indirect = &( (*indirect)->next );
    	}
    	ListNode* newNode = new ListNode( newVal );
        newNode->next = *indirect;
        *indirect = newNode;
    }
};

int main() {
	return 0;
}
