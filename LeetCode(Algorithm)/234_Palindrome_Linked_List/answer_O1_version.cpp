// Try to do it within O(1) space complexity...
// Result: 26ms

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if ( !head || !head->next ) {   // 0 or 1 element
            return true;
        }


        // Get the head of second half.
        ListNode *p1, *p2;
        p1 = p2 = head;
        while ( p2->next && p2->next->next ) {
            p1 = p1->next;
            p2 = p2->next->next;
        }


        // Reverse the second sublist and judge palindromity.
        ListNode *temp = p1;
        reverseList( p1->next );
        bool result = true;
        p1 = p1->next;
        while ( p1 ) {
            if ( head->val != p1->val ) {
                result = false;
                break;
            } else {
                head = head->next;
                p1 = p1->next;
            }
        }


        // We'd better restore it to the original list.
        //reverseList( temp->next );

        // Return the result.
        return result;
    }

    void reverseList(ListNode* &head) {
        ListNode *last = NULL;
        ListNode *next;
        while ( head ) {
            next = head->next;
            head->next = last;
            last = head;
            head = next;
        }

        head = last;    // Change the head of the list.
    }
};


int main(int argc, char const *argv[]) {
    
    return 0;
}