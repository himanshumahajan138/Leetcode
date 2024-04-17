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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *oddhead=head ,*even=head->next,*evenhead=head->next;
        while(even!=NULL&&even->next!=NULL){
            oddhead->next=oddhead->next->next;
            even->next=even->next->next;

            oddhead=oddhead->next;
            even=even->next;
        }
        oddhead->next=evenhead;
        return head;
    }
};