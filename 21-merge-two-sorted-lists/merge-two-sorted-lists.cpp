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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *e1=list1 , *e2=list2;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while(e1!=NULL&&e2!=NULL){
            if(e1->val<e2->val){
                temp->next=e1;
                temp=e1;
                e1=e1->next;
            }
            else{
                temp->next=e2;
                temp=e2;
                e2=e2->next;
            }
        }
        if(e1!=NULL)temp->next=e1;
        else temp->next=e2;
        return dummy->next;
    }
};