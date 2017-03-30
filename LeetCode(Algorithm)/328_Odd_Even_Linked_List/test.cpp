#include <iostream>
#include <fstream>
#include <cstdlib>  // atoi
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
            ret += to_string( head->val );
            head = head->next;
        }
        ret += "]";
        return ret;
    }

// --------------------------------------------------------

public:
    ListNode* oddEvenList(ListNode* head) {
        if ( !head ) return NULL;

        ListNode *odd_head = head;
        ListNode even_dummy(0);

        ListNode *odd = odd_head, *even = &even_dummy;

        while ( true ) {

            if ( odd->next ) {
                even->next = odd->next;
                even = even->next;
            } else {
                even->next = NULL;
                break;
            }

            if ( even->next ) {
                odd->next = even->next;
                odd = odd->next;
            } else {
                odd->next = NULL;
                break;
            }
        }
        
        odd->next = even_dummy.next;

        return odd_head;
    }

    void go() {
        __head = oddEvenList( __head );
    }

};

int main() {
    ifstream cin("in.txt");

    SinglyList list;

    string input;
    while ( cin >> input ) {
        list.deserialize( input );
        cout << list.serialize() << endl;

        list.go();

        cout << list.serialize() << endl;
    }

    return 0;
}
