/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int>st;
         ListNode* curr=head;
      
         while(curr != NULL){
            st.push(curr->val);
            curr=curr->next;
         }
         int n=st.size();
         curr=head;
         
          int sum=0;
           for(int i = 0; i < n/2; i++){
            sum = max(sum, curr->val + st.top());
            curr = curr->next;
            st.pop();
        }
          return sum;   
        
    }
};