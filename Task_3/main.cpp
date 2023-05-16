#include<iostream>
#include"LinkedList.h"

void printList(LinkedList list)
{
    LinkedList b;
    b = list;
    std::cout << "copy and assign" << b << std::endl;
}

void swap(int& a, int& b)
{
    a ^= b ^= a ^= b;
}

void reverse(LinkedList& list)
{
    for (int i = 0; i < list.len() / 2; ++i)
    {
        swap(list[i], list[list.len() - 1 - i]);
    }
}

LinkedList createList(int n) {
    LinkedList list;
    for (int i = 0; i < n; ++i) {
        list.push_back(i);
    }
    return list;
}

int main(int argc, char* argv[])
{
    LinkedList list;
    std::cout << list << std::endl;
    list.push_forward(1);
    std::cout << list << std::endl;
    list.push_back(5).push_back(6);
    std::cout << list << std::endl;
    list.insert(3, 1).insert(2, 1).insert(4, 3);
    std::cout << list << std::endl;
    std::cout << "EXTRACT FORWARD    : " << list.extract_forward() << " " << list << std::endl;
    std::cout << "EXTRACT BACKWARD   : " << list.extract_back() << " " << list << std::endl;
    std::cout << "EXTRACT FROM POS 2 : " << list.extract(2) << " " << list << std::endl;
    std::cout << "EXTRACT FROM POS 2 : " << list.extract(2) << " " << list << std::endl;
    std::cout << "EXTRACT FROM POS 2 : " << list.extract(2) << " " << list << std::endl;
    std::cout << "EXTRACT FROM POS 0 : " << list.extract(0) << " " << list << std::endl;
    std::cout << "EXTRACT FORWARD    : " << list.extract_forward() << " " << list << std::endl;

    printList(list);

    list.push_back(0).push_back(1).push_back(2).push_back(3).push_back(4).push_back(5).push_back(6);
    std::cout << list << std::endl;
    for (int i = 0; i < list.len(); ++i)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    reverse(list);
    std::cout << list << std::endl;


    // testing swap , merge , mergesort :
    LinkedList list1 = createList(10);
    std::cout << "Original list: " << list1 << std::endl;
    list1.swap(1, 8);
    std::cout << "After swapping elements at positions 1 and 8: " << list1 << std::endl;



    LinkedList list2 = createList(5);
    LinkedList list3 = createList(5);
    std::cout << "List 2: " << list2 << std::endl;
    std::cout << "List 3: " << list3 << std::endl;
    LinkedList mergedList = LinkedList::merge(list2, list3);
    std::cout << "Merged list: " << mergedList << std::endl;



    LinkedList list4;
    list4.push_back(5).push_back(1).push_back(6).push_back(3).push_back(4).push_back(2);
    std::cout << "Unsorted list: " << list4 << std::endl;
    list4.mergeSort();
    std::cout << "Sorted list: " << list4 << std::endl;



    return EXIT_SUCCESS;
}
