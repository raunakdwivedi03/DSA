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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL && head->next == NULL) {
            return nullptr;
        }
        //length of linked list 
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        //front temp
        ListNode* fronttemp=head;
        for(int i=1;i<k;i++){
          fronttemp=fronttemp->next;
        }

        //  back temp
        ListNode* backtemp=head;
        for(int i=1;i<n-k+1;i++){
            backtemp=backtemp->next;
        }
        // now swap the values;
        int value;
       value= fronttemp->val;
        fronttemp->val=backtemp->val;
        backtemp->val=value;

        return head;
    }
};