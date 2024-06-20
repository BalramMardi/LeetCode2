class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head==NULL) return NULL;
        
        ListNode* tempa=head;
        int l=0;
        while(tempa!=NULL){
            tempa=tempa->next;
            l++;
        }
        tempa=head;
        for(int i=1;i<k;i++){
            tempa=tempa->next;
        }
        ListNode* tempb=head;
        for(int i=1;i<=l-k;i++){
            tempb=tempb->next;
        }
        int c=tempa->val;
        tempa->val=tempb->val;
        tempb->val=c;
        return head;  
    }
};