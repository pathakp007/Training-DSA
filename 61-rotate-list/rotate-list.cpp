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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0){
            return head;
        }

        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Step 2: Make circular
        temp->next = head;

        // Step 3: Reduce k
        k = k % n;
        int move = n - k;

        // Step 4: Find new tail
        ListNode* newTail = head;
        for (int i = 1; i < move; i++) {
            newTail = newTail->next;
        }

        // Step 5: Set new head
        ListNode* newHead = newTail->next;

        // Step 6: Break circle
        newTail->next = NULL;

        return newHead;
    }
};