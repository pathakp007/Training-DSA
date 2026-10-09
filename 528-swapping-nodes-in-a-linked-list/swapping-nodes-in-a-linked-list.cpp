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
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;

        ListNode* temp = head;

        while(temp != nullptr){
            if(p2 != nullptr){
                p2 = p2->next;
            }

            k--;

            if(k == 0){
                p1 = temp;
                p2 = head;
            }

            temp = temp->next;
        }

        swap(p1->val, p2->val);

        return head;
    }
};