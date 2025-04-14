/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        return NULL;

        unordered_map<ListNode*,bool>map;
            ListNode* temp=head;
         

          while(temp!=NULL){
           if( map[temp]){
            return temp;
           }

          
        map[temp]=true;
        temp=temp->next;
          }
        return NULL;
    
    }
};