#include <iostream>

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
ListNode* mergeTwoLists(ListNode* list1 , ListNode* list2){
    if(list1) return list2;
    if(list2) return list1;
    ListNode* merged ;
    if(list2->val > list1->val) {
        merged = list2;
        list2 = list2->next;
    }
    else {
        merged = list1;
        list1 = list1->next;
    }
    while(!list1 or !list2){
        if(list1){
            while(!list2){
                merged->next = list2;
                list2 = list2->next;
            }
            break;
        }
        if(list2){
            while(!list1){
                merged->next = list1;
                list1 = list1->next;
            }
            break;
        }
        if(list2->val > list1->val){
            merged->next = list2;
            list2 = list2->next;
        }
        else {
            merged->next = list1;
            list1 = list1->next;
        }

    }
    return merged;

}
