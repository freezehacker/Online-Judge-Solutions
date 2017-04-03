#include <iostream>
#include <fstream>
#include <cstdlib>  // atoi
#include <sstream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SinglyList {
public:
    SinglyList(): __head(NULL), __size(0) {}

    ~SinglyList() {
        _destroy( __head );
        __size = 0;
    }

    SinglyList(string str) {
        __head = _deserialize( str );
        updateSize();
    }

    void deserialize(string str) {
        // First clear the current list.
        _destroy( __head );

        // Then build a new list.
        __head = _deserialize( str );

        updateSize();
    }

    string serialize() const {
        return _serialize( __head );
    }

    void insert(int newValue) {
        ListNode** indir = &__head;
        while ( *indir ) {
            indir = &( (*indir)->next );
        }
        *indir = new ListNode( newValue );
        ++__size;
    }

    void updateSize() {
        ListNode* p = __head;
        int size = 0;
        while ( p ) {
            ++size;
            p = p->next;
        }
        __size = size;
    }

private:
    ListNode* __head;
    int __size;

private:
    void _destroy(ListNode* &head) {
        ListNode* entry;
        while ( head ) {
            entry = head;
            head = head->next;
            delete entry;
        }
        head = NULL;
    }

    ListNode* _deserialize(string str) {
        ListNode dummy(0);
        ListNode *list = &dummy;
        str = str.substr(1, str.size() - 2);
        string numberStr("");
        for (int i = 0, size = str.size(); i < size; ++i) {
            if ( str[i] == ',' ) {
                int number = atoi( numberStr.c_str() );
                list->next = new ListNode( number );
                list = list->next;
                numberStr = ""; // Reset.
            } else {
                numberStr.push_back( str[i] );
            }
        }
        // Remember to add the last one.
        list->next = new ListNode( atoi( numberStr.c_str() ) );
        return dummy.next;
    }

    string _serialize(ListNode* head) const {
        string ret = "[";
        bool isFirst = true;
        while ( head ) {
            if ( !isFirst ) {
                ret += ",";
            } else {
                isFirst = false;
            }
            ret += int_to_string( head->val );
            head = head->next;
        }
        ret += "]";
        return ret;
    }

    string int_to_string(int n) const {
        stringstream ss;
        ss << n;
        string s;
        ss >> s;
        return s;
    }

// --------------------------------------------------------

public:
    bool isSelfPalindrome() {
        return isPalindrome( __head );
    }

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


        // Restore it to the original list.
        reverseList( temp->next );

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

int main() {
    ifstream cin("in.txt");

    SinglyList list;

    string input;
    while ( cin >> input ) {
        cout << input << endl;

        list.deserialize( input );
        cout << ( list.isSelfPalindrome() ? "Palindrome" : "Not palidrome" ) << endl;

        cout << list.serialize() << endl << endl;
    }

    return 0;
}
