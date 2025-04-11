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

  
    ListNode* middleNode(ListNode* head) {
        if(head ==NULL)
        return NULL;
 
       ListNode* temp=head;
        stack<ListNode*>st;
        
        int count=0;
        while(temp!=NULL){
        st.push(temp);
        temp=temp->next;
        count++;
}
       
       int mid=count/2;

         temp=head;
       for(int i=0;i<mid;i++){
        temp=temp->next;
       }

       return temp;
    }
};