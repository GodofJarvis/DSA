/* Merge two sorted list
 * https://leetcode.com/problems/merge-two-sorted-lists/
 */
 
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *l3 = nullptr;
    ListNode *head = nullptr;
    
    int val;
    while (l1 != nullptr && l2 != nullptr){
        if (l1->val <= l2->val){
            val = l1->val;
            l1 = l1->next;
        }
        else {
            val = l2->val;
            l2 = l2->next;
        }

        if (head == nullptr){
            ListNode *tmp = new ListNode(val);
            head = tmp;
            l3 = head;
        }
        else {
            ListNode *tmp = new ListNode(val);
            l3->next = tmp;
            l3 = l3->next;
        }
    }

    // Point next of last node of l3 to non-empty list,
    // if & only if, either one of the list is non-empty.
    
    ListNode *tmp = nullptr;
    if (l1 != nullptr){
        tmp = l1;
    }
    if (l2 != nullptr){
        tmp = l2;
    }

    if (tmp != nullptr){
        if (head == nullptr){
            head = tmp;
        }
        else {
            l3->next = tmp;
        }
    }
    return head;
}

int main(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(5);
    l2->next->next->next->next = new ListNode(6);
    
    ListNode *mergedList = mergeTwoLists(l1, l2);
    ListNode *l3 = mergedList;
    for (;l3!= nullptr; l3=l3->next){
        cout<<l3->val<<" ";
    }
}
