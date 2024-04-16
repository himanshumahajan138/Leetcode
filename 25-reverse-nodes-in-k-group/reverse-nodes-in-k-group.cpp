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

    ListNode *find_k(ListNode *head,int k){
        ListNode *temp = head;
        while(temp!=NULL&&k>1){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode *rev(ListNode *head){
        if(head==NULL||head->next==NULL)return head;
        ListNode *newhead=rev(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL){
            ListNode *knode=find_k(temp,k);
            if(knode==NULL){
                if(prev)prev->next=temp;
                break;
            }
            ListNode *nextnode=knode->next;
            knode->next=NULL;
            rev(temp);
            if(temp==head){
                head=knode;
            }
            else{
                prev->next= knode;
            }
            prev=temp;
            temp=nextnode;
        }
        return head;
    }
};