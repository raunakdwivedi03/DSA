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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
       ListNode* curr= list1;
       ListNode* prev= list1;
       ListNode* temp;
      
      int indx=0;
      while( indx< a-1){
        prev=prev->next;
        indx++;
      }
        curr=prev;
        while(indx < b){
            curr=curr->next;
            indx++;
        }
        temp=curr->next;

        prev->next=list2;
        while(prev->next != NULL ){
            prev=prev->next;
        }
        prev->next=temp;

        return list1;
    }
};