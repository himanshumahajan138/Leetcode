/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    Node* insert_in_between(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            Node *copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }
        delete(temp);
        return head;
    }
    Node* connect_random(Node* head){
        Node *temp=head;
        while(temp!=NULL){
            if(temp->random)temp->next->random=temp->random->next;
            else temp->next->random=NULL;
            temp=temp->next->next;
        }
        delete(temp);
        return head;
    }
    Node* get_deep_copy(Node* head){
        Node *temp=head , *dummyhead= new Node(-1);
        Node *dummy=dummyhead;
        while(temp!=NULL){
            dummy->next=temp->next;
            dummy=dummy->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        delete(temp);
        head=dummyhead->next;
        delete(dummyhead);
        return head; 
    }
    Node* copyRandomList(Node* head) {
        insert_in_between(head);
        connect_random(head);
        return get_deep_copy(head);
    }
};