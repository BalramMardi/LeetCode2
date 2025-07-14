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
    int getDecimalValue(ListNode* head) {
        
        int num=0;
        while(head){
            num = ((num << 1)|(head->val));
            head = head->next;
        }
        
        return num;
    }
};


/* class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        ListNode* curr =head;
        string bin="";
        while(curr){
            bin += to_string(curr->val);
            curr = curr->next;
        }

        int num=0;
        int p=0;
        for(int i=bin.size()-1;i>=0;i--){
            num += ((bin[i]-'0')*(pow(2,p)));
            p++;
        }
        return num;
    }
}; */