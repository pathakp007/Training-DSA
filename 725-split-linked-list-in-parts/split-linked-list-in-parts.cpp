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
        ListNode* curr = head;
        int L = 0;
        while(curr){
            L++;
            curr = curr->next;
        }

        int eachbucket = L/k;
        int reminder = L%k;

        vector<ListNode*> result(k,NULL);
        curr = head;
        ListNode* prev = NULL;

        for(int i = 0; curr && i < k; i++){
            result[i] = curr;

            for(int i = 0; i < eachbucket + (reminder > 0 ? 1:0); i++){
                prev = curr;
                curr = curr->next;
            }

            prev->next = nullptr;
            reminder--;
        }

        return result;
    }
};