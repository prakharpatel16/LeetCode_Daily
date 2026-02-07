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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        stack<int> st;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> nextgreater(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() and st.top() <= arr[i]){
                st.pop();
            }
            nextgreater[i] = st.empty() ? 0 : st.top();
            st.push(arr[i]);
        }
        return nextgreater;
    }
};