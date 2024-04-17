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
 ListNode *rev(ListNode *head){
    if (head==NULL || head->next==NULL)return head;
    ListNode *newHead = rev(head->next);
    ListNode *front = head->next;
    front->next=head;
    head->next = NULL;
    return newHead;
 }

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *newHead = rev(slow->next);
        ListNode *firstHead = head;
        ListNode *secondHead = newHead;
        while(secondHead!=NULL){
            if(secondHead->val!=firstHead->val){
                rev(newHead);
                return false;
            }
            firstHead=firstHead->next;
            secondHead=secondHead->next;
        }
        rev(newHead);
        return true;
    }
};