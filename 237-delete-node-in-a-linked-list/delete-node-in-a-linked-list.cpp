/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    void deleteNode(ListNode* node) {
        /*
        Intitutive solution 

        ListNode *nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        nextNode->next = nullptr;
        delete(nextNode);
        */
        node->val=node->next->val;
        node->next=node->next->next;
    }
};