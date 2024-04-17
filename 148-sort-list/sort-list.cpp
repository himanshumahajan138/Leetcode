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
const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
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

    ListNode *node_before_mid(ListNode *head){
        ListNode *slow=head , *fast=head->next->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode *nbm=node_before_mid(head);
        ListNode *right= nbm->next;
        nbm->next=nullptr;
        ListNode *left=head;
        left = sortList(left);
        right = sortList(right);
        head = merge(left,right);
        return head;
    }
};