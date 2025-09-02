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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return nullptr;

        int prefixSum = 0;
        unordered_map<int, ListNode*> map;

        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        map[0] = dummynode;

        while (head != nullptr) {
            prefixSum += head->val;

            if (map.find(prefixSum) != map.end()) {
                // Node where this prefix sum was previously seen
                ListNode* start = map[prefixSum];

                // Delete intermediate prefix sums
                int pSum = prefixSum;
                ListNode* temp = start->next;
                while (temp != head) {
                    pSum += temp->val;
                    map.erase(pSum);
                    temp = temp->next;
                }

                // Connect start to node after head
                start->next = head->next;
            } else {
                map[prefixSum] = head;
            }
            head = head->next;
        }

        return dummynode->next;
    }
};
