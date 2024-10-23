/*
Problem name: 21. Merge Two Sorted Lists
Problem link: https://leetcode.com/problems/merge-two-sorted-lists/
Explanation : https://leetcode.com/problems/merge-two-sorted-lists/solutions/2682085/java-0ms-100-easy-understanding
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* mergedHead = NULL;

        if (list1->val < list2->val) {
            mergedHead = list1;
            list1 = list1->next;
        } else {
            mergedHead = list2;
            list2 = list2->next;
        }

        ListNode* current = mergedHead;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != NULL) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return mergedHead;
    }
};