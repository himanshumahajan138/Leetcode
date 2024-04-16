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
    ListNode* find_k_node(ListNode *head,int k){
        ListNode *temp=head;
        int cnt=1;
        while(temp!=NULL){
            if(cnt==k)return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)return head;
        ListNode *temp=head;
        int cnt=1;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(k%cnt==0)return head;
        k=k%cnt;
        ListNode *knode=find_k_node(head,cnt-k);
        ListNode *newhead = knode->next;
        knode->next=NULL;
        temp->next=head;
        return newhead;
    }
};