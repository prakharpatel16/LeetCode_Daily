#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;

        ListNode* newNode;
        while(current != NULL){
            newNode = current->next;
            current->next = prev;
            prev = current;
            current = newNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* reversedList = reverseList(head);
        int carry = 0;
        ListNode* current = reversedList, *previous = nullptr;
        while(current != nullptr){
            int newValue = current->val * 2 + carry;
            current->val = newValue % 10;
            if(newValue > 9){
                carry = 1;
            }
            else{
                carry = 0;
            }
            previous = current;
            current = current->next;
        }
        if(carry != 0){
            ListNode* extraNode = new ListNode(carry);
            previous->next = extraNode;
        }
        ListNode* result = reverseList(reversedList);
        return result;
    }
};