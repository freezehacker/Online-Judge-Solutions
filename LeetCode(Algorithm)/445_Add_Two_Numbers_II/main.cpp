struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = listToString( l1 );
        string s2 = listToString( l2 );

        return addTwoStrings( s1, s2 );
    }

    string listToString(ListNode* head) {
        string ret;
        while ( head ) {
            ret.push_back( head->val + '0' );
            head = head->next;
        }
        return ret;
    }

    ListNode* addTwoStrings(string &s1, string &s2) {
        while ( s1.size() < s2.size() ) {
            s1 = "0" + s1;
        }
        while ( s1.size() > s2.size() ) {
            s2 = "0" + s2;
        }

        ListNode* ret = NULL;

        stack<int> values;
        int size = s1.size();
        int carry = 0;
        for (int i = size - 1; i >= 0; --i) {
            int temp = (s1[i] - '0') + (s2[i] - '0') + carry;
            carry = temp / 10;
            values.push( temp % 10 );
        }
        if (carry) {
            values.push( carry );
        }

        ListNode* tail;
        while ( !values.empty() ) {
            int value = values.top();
            values.pop();
            if ( !ret ) {
                ret = new ListNode( value );
                tail = ret;
            } else {
                tail->next = new ListNode( value );
                tail = tail->next;
            }
        }

        return ret;
    }
};