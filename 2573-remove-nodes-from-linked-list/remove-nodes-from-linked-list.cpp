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
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *prev=nullptr;
        ListNode *temp=head;
        while(temp!=NULL){
            ListNode *nexti=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nexti;
        }
        temp=prev;
        ListNode *nexti=temp->next;

        while(nexti!=NULL){
            if(nexti->val>=temp->val){
                temp=nexti;
                nexti=nexti->next;
            }
            else{
                temp->next=nexti->next;
                nexti->next=NULL;
                delete(nexti);
                nexti=temp->next;
            }
        }
        temp=prev;
        prev=nullptr;
        while(temp!=NULL){
            ListNode *nexti=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nexti;
        }
        return prev;
    }
};