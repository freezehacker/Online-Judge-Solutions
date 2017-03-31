// Try to do it within O(1) space complexity...

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
        if ( !head ) return true;

        ListNode* second_half = divide( head );
        ListNode* first_half = head;    // Easy to understand

    }

    ListNode* divide(ListNode* list) {
        ListNode* p1 = list;
        ListNode* p2 = list->next;

    }
};


int main(int argc, char const *argv[]) {
    
    return 0;
}