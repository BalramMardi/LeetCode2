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
        if(head == 0) return NULL;

        int len=0;
        ListNode* temp=head;
        ListNode* tail=NULL;
        while(temp){
            if(temp->next==NULL){
                tail=temp;
            }
            temp=temp->next;
            len++;
        }

        k = k % len;
        temp=head;

        for(int i=1;i<(len-k);i++){
            temp = temp->next;
        }

        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};