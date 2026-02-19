class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = head;
        ListNode* prev = dummy;

        while (temp != NULL) {

            // if duplicate found
            if (temp->next != NULL && temp->val == temp->next->val) {

                // skip all nodes with same value
                while (temp->next != NULL && temp->val == temp->next->val) {
                    temp = temp->next;
                }

                // remove duplicates completely
                prev->next = temp->next;
            }
            else {
                prev = prev->next;
            }

            temp = temp->next;
        }

        return dummy->next;
    }
};
