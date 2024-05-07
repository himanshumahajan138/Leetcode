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
    int calculate(ListNode* head, int carry) {
        if (head->next != NULL) {
            carry = calculate(head->next, carry);
        }
        int mul = head->val * 2 + carry;
        if (mul > 9) {
            carry = mul / 10;
            mul = mul % 10;
        } else
            carry = 0;

        head->val = mul;

        return carry;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = calculate(head, 0);
        if (carry > 0) {
            return new ListNode(carry, head);
        }
        return head;
    }
};