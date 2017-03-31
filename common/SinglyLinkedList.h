#ifndef __SINGLY_LINKED_LIST__
#define __SINGLY_LINKED_LIST__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node;    // Forward declaration.
typedef bool UNARY_PREDICATE(const Node*);
const int ERROR_VALUE = 0x3f3f3f3f;

struct Node {
    int value;
    Node* next;
    Node(int value, Node* next = NULL): value(value), next(next) {}
};

class SinglyLinkedList {
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insert(int value);
    void insertAt(int pos, int value);
    void pushBack(int value);
    void pushFront(int value);

    void removeAt(int pos);
    void removeValue(int valueToRemove);
    void removeIf(UNARY_PREDICATE predicate);
    void popBack();
    void popFront();

    void set(int pos, int newValue);

    vector<int> getAll() const;
    void print(const string &delim=",") const;
    int get(int pos) const;
    int count(int value) const;
    int size() const;

private:
    Node* __head;   // Head of this list.
    int __size;

private:
    void __destroy(Node* &head);
};

#endif
