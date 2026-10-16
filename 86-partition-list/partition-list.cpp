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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* smallptr = small;
        ListNode* largeptr = large;

        while(head != NULL){
            if(head->val < x){
                smallptr->next = head;
                smallptr = smallptr->next;
            }
            else{
                largeptr->next = head;
                largeptr = largeptr->next;
            }

            head = head->next;
        }

        smallptr->next = large->next;
        largeptr->next = NULL;
        return small->next;
    }
};