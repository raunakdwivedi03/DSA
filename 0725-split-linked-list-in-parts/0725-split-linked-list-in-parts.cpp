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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       
        ListNode* curr=head;
        int n=0;
        while(curr != NULL){
            n++;
            curr=curr->next;
        }
        int eachBuckNode = n/k;
        int remainingNode = n%k;

        vector<ListNode*>result(k,NULL);
        ListNode* prev=NULL;
        curr=head;

        for(int i=0;curr != NULL && i<k;i++){
            result[i] = curr;
            int partSide = eachBuckNode;
            if(remainingNode >0){
                partSide += 1;
                remainingNode--;
            }
            for(int count=0; count<partSide;count++){
            prev=curr;
         
            curr=curr->next;
        }
        if(prev != NULL)
        prev->next=NULL;
       
        }
        return result;
    }
};