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
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                break;
            }
        }

        if(slow != fast){
            return nullptr;
        }

        ListNode* P = head;

        while(P != slow){
            P = P->next;
            slow = slow->next;
        }

        return P;
    }
};