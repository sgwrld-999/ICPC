#include<bits/stdc++.h>
using namespace std;
/*
Problem name: 206. Reverse Linked List
Problem link: https://leetcode.com/problems/reverse-linked-list/
Explanation : https://leetcode.com/problems/reverse-linked-list/solutions/2682085/java-0ms-100-easy-understanding
*/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* present = head;
        ListNode* nextNode = NULL;

        while (present != NULL) {
            nextNode = present->next;
            present->next = previous;
            previous = present;
            present = nextNode;
        }

        return previous;
    }
};

