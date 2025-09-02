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
        vector<int>vector;
      
      ListNode* curr= head;

      while(curr != NULL){
        vector.push_back(curr->val);
        curr=curr->next;
      }
      int result=0;
      int i=0;
      int j=vector.size()-1;
      while(i<j){
        result=max(result,vector[i]+vector[j]);
        i++;
        j--;
      }
      return result; 
      }
};