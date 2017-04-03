// O(n) space, O(n) time.
// Result: 33ms

#include <iostream>
#include <vector>
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

        vector<int> values;
        while ( head ) {
            values.push_back( head->val );
            head = head->next;
        }

        for (int i = 0, size = values.size(), mid = size / 2; i < mid; ++i) {
            if ( values[i] != values[size - 1 - i] ) {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
    
    return 0;
}