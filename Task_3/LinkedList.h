#pragma once
#include<ostream>

struct Node {
    int data;
    Node* next;
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    Node(const Node& node) : data(node.data), next(nullptr) {}
    ~Node() { next = nullptr; }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int elcount;

    int IndexValid(int pos);
    void removeData(Node* node);
    Node* copyData(Node* node) const;
    int nan = 0;

    Node* extractNode(int pos);
    void insertNode(Node* node, int pos);

public:
    LinkedList() : head(nullptr), tail(nullptr), elcount(0) {};
    LinkedList(const LinkedList& list);
    ~LinkedList();
    LinkedList& push_forward(int el);
    LinkedList& push_back(int el);
    LinkedList& insert(int el, int pos);
    int extract_forward();
    int extract_back();
    int extract(int pos);
    LinkedList& remove_forward();
    LinkedList& remove_back();
    LinkedList& remove(int pos);
    void clear();
    LinkedList& operator=(const LinkedList& list);
    int& operator[](int index);
    int len() { return elcount; };
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);

    void swap(int i, int j);
    static const LinkedList merge(const LinkedList &list1, const LinkedList &list2);

    void mergeSort();

};

struct Stack : private LinkedList {
    void push(int el) { push_forward(el); };
    int pop() { return extract_forward(); };
};

struct Queue : private LinkedList {
    void enqueue(int el) { push_back(el); };
    int dequeue() { return extract_forward(); };
};

struct Deck : private LinkedList {
    void push_front(int el) { push_front(el); };
    void push_back(int el) { push_back(el); };
    int pop_front() { return extract_forward(); };
    int pop_back() { return extract_back(); };
};
