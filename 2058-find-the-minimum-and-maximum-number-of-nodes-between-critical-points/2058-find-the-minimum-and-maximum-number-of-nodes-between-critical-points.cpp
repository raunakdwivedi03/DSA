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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prevVal = 0;
        int currVal = 0;
        int nextVal = 0;

        int minDist = INT_MAX;
        int firstCriticalPos = -1;
        int prevCriticalPos = -1;

        int i = 0;
        vector<int> result = {-1, -1};

        while (head != NULL) {
            prevVal = currVal;
            currVal = nextVal;
            nextVal = head->val;

            if (i >= 2) {  // only start checking after 3 nodes are ready
                if ((prevVal > currVal && currVal < nextVal) || 
                    (prevVal < currVal && currVal > nextVal)) {

                    if (firstCriticalPos == -1) {
                        firstCriticalPos = i - 1;  // position of currVal
                    } else {
                        minDist = min(minDist, (i - 1) - prevCriticalPos);
                        result = {minDist, (i - 1) - firstCriticalPos};
                    }
                    prevCriticalPos = i - 1;
                }
            }

            i++;
            head = head->next;
        }
        return result;
    }
};
