#include "LinkedList.h"

int LinkedList::IndexValid(int pos)
{
    return (pos >= 0 && pos < elcount);
}

Node* LinkedList::copyData(Node* node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }
    Node* newNode = new Node(node->data);

    Node* tempNode = newNode;
    Node* temp = head->next;
    while (temp != nullptr)
    {
        tempNode->next = new Node(temp->data);
        temp = temp->next;
        tempNode = tempNode->next;
    }

    return newNode;
}

void LinkedList::removeData(Node* node)
{
    while (node != nullptr)
    {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

void LinkedList::clear()
{
    if (head != nullptr)
    {
        removeData(head);
    }
    tail = nullptr;
    elcount = 0;
}

int& LinkedList::operator[](int index)
{
    if (!IndexValid(index))
    {
        return nan;
    }
    Node* node = head;
    while (index > 0)
    {
        --index;
        node = node->next;
    }
    return node->data;
}

LinkedList::LinkedList(const LinkedList & list)
{
    elcount = list.elcount;
    head = list.copyData(list.head);
    tail = head;
    if (tail != nullptr)
    {
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
    }
}

LinkedList::~LinkedList()
{
    clear();
}

LinkedList& LinkedList::push_forward(int el)
{
    head = new Node(el, head);
    if (tail == nullptr)
    {
        tail = head;
    }
    ++elcount;
    return *this;
}

LinkedList& LinkedList::push_back(int el)
{
    if (elcount == 0)
    {
        return push_forward(el);
    }
    tail->next = new Node(el);
    tail = tail->next;
    ++elcount;
    return *this;
}

LinkedList& LinkedList::insert(int el, int pos)
{
    if (!IndexValid(pos))
    {
        return *this;
    }
    if (pos == 0)
    {
        return push_forward(el);
    }
    if (pos == elcount)
    {
        return push_back(el);
    }
    Node* temp = head;
    while (pos > 1)
    {
        temp = temp->next;
        --pos;
    }
    temp->next = new Node(el, temp->next);
    ++elcount;
    return *this;
}

int LinkedList::extract_forward()
{
    if (head == nullptr)
    {
        return 0;
    }
    if (elcount == 1)
    {
        tail = nullptr;
    }
    int result = head->data;
    Node* oldHead = head;
    head = head->next;
    delete oldHead;
    --elcount;
    return result;
}

int LinkedList::extract_back()
{
    if (elcount < 2)
    {
        return extract_forward();
    }

    int result = tail->data;

    Node* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    tail = temp;

    --elcount;
    return result;
}

int LinkedList::extract(int pos)
{
    if (!IndexValid(pos))
    {
        return 0;
    }
    if (pos == 0)
    {
        return extract_forward();
    }
    if (pos == elcount - 1)
    {
        return extract_back();
    }

    Node* temp = head;
    while (pos > 1)
    {
        temp = temp->next;
        --pos;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    int result = toDelete->data;
    delete toDelete;
    --elcount;
    return result;
}

LinkedList& LinkedList::remove_forward()
{
    extract_forward();
    return *this;
}

LinkedList& LinkedList::remove_back()
{
    extract_back();
    return *this;
}

LinkedList& LinkedList::remove(int pos)
{
    extract(pos);
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList & list)
{
    Node* temp = list.head;
    stream << "{" << list.elcount << "}[ ";
    if (temp == nullptr)
    {
        stream << "EMPTY ";
    }
    while (temp != nullptr)
    {
        stream << temp->data << " ";
        temp = temp->next;
    }
    stream << "]";
    return stream;
}




LinkedList& LinkedList::operator=(const LinkedList& list)
{
    if(this == &list)
        return *this;

    clear();
    elcount = list.elcount;
    head = copyData(list.head);
    tail = head;
    while(tail && tail->next != nullptr) {
        tail = tail->next;
    }
    return *this;
}


Node* LinkedList::extractNode(int pos) {
    if (!IndexValid(pos)) return nullptr;
    Node* node;
    if (pos == 0) {
        node = head;
        head = head->next;
    } else {
        Node* prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        node = prev->next;
        prev->next = node->next;
    }
    --elcount;
    if (elcount == 0) head = tail = nullptr;
    else if (node == tail) tail = head;
    node->next = nullptr;
    return node;
}

void LinkedList::insertNode(Node* node, int pos) {
    if (!IndexValid(pos)) return;
    if (pos == 0) {
        node->next = head;
        head = node;
    } else {
        Node* prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
    }
    ++elcount;
    if (elcount == 1) head = tail = node;
    else if (node->next == nullptr) tail = node;
}

void LinkedList::swap(int i, int j) {
    if (!IndexValid(i) || !IndexValid(j)) return;
    if (i > j) return swap(j, i);
    Node* second = extractNode(j);
    Node* first = extractNode(i);
    insertNode(second, i);
    insertNode(first, j);
}

const LinkedList LinkedList::merge(const LinkedList &list1, const LinkedList &list2) {
    LinkedList result;
    Node* node1 = list1.head;
    Node* node2 = list2.head;
    while (node1 != nullptr && node2 != nullptr) {
        if (node1->data < node2->data) {
            result.push_back(node1->data);
            node1 = node1->next;
        } else {
            result.push_back(node2->data);
            node2 = node2->next;
        }
    }
    while (node1 != nullptr) {
        result.push_back(node1->data);
        node1 = node1->next;
    }
    while (node2 != nullptr) {
        result.push_back(node2->data);
        node2 = node2->next;
    }
    return result;
}

void LinkedList::mergeSort() {
    if (elcount < 2) return;
    LinkedList list1;
    LinkedList list2;
    Node* node = head;
    for (int i = 0; i < elcount; i++) {
        if (i < elcount / 2) list1.push_back(node->data);
        else list2.push_back(node->data);
        node = node->next;
    }
    list1.mergeSort();
    list2.mergeSort();
    *this = merge(list1, list2);
}
