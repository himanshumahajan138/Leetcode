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
int q = [] {
    ofstream ans("user.out");
    vector<int> numbers;
    char ch;
    while (cin >> ch) {
        int sum = 0, c = 0;
        numbers.clear();
        do {
            numbers.push_back(getchar() - '0');
            ch = getchar();
        } while (ch == ',');
        cin >> ch;
        do {
            ch = getchar();
            if (c < numbers.size())
                sum += numbers[c];
            sum += ch - '0';
            ans << (c ? ',' : '[') << sum % 10;
            sum /= 10;
            c++;
            ch = getchar();
        } while (ch == ',');
        while (c < numbers.size()) {
            sum += numbers[c];
            ans << ',' << sum % 10;
            sum /= 10;
            c++;
        }
        if (sum)
            ans << ",1";
        ans << "]" << endl;
    }
    exit(0);
    return 0;
}();
//Solution starts here;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=l1 , *temp2=l2 , *dummy= new ListNode(-1); 
        ListNode *temp=dummy;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum =carry;
            if(temp1!=NULL)sum+=temp1->val;
            if(temp2!=NULL)sum+=temp2->val;
            ListNode *newNode = new ListNode(sum%10);
            temp->next=newNode;
            temp=temp->next;
            carry = sum/10;
            if(temp1!=NULL)temp1=temp1->next;
            if(temp2!=NULL)temp2=temp2->next;
        }
        if(carry){
            ListNode *newnode= new ListNode(carry);
            temp->next=newnode;
        }
        ListNode *head=dummy->next;
        delete(dummy);
        return head ;
    }
};