class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

       
        ListNode* temp = head;
        int check = 0;
        while (temp != NULL && check < k) {
            temp = temp->next;
            check++;
        }
        if (check < k) return head;

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;

        while(curr!=NULL && cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if(next != NULL){
            head->next = reverseKGroup(next,k);
        }

        return prev;
    }
};