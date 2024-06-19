class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        dummy->next = list1;

        ListNode* before = dummy;
        ListNode* after = list1;
        
        // Move 'after' to the node at index b+1
        for (int i = 0; i < b + 1; ++i) {
            after = after->next;
        }
        
        // Move 'before' to the node at index a-1
        for (int i = 0; i < a; ++i) {
            before = before->next;
        }
        
        // Connect 'before' to the head of list2
        before->next = list2;
        
        // Find the end of list2
        ListNode* endOfList2 = list2;
        while (endOfList2->next != nullptr) {
            endOfList2 = endOfList2->next;
        }
        
        // Connect the end of list2 to 'after'
        endOfList2->next = after;
        
        return dummy->next;
    }
};
