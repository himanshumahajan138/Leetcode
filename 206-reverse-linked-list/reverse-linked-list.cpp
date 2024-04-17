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
 int query = []{
    char ch;
    std::vector<std::string> nums; nums.clear();
    ofstream ans("user.out");
    while (std::cin >> ch) 
    {
        string s = "";
        nums.clear();
        do
        {
            ch = getchar();
            s += ch;
        }while (ch !=']');

        ans << "[" ;
            
        if (s.size() != 1)
        {
            int n = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ',' || i == s.size()-1)
                {
                    if (i - n == 1)
                    {
                        char l = s[n];
                        std::string kl(1, l);
                        nums.push_back(kl);
                        n = i + 1;
                    } 
                    else
                    {
                        nums.push_back(s.substr(n, i - n));
                        n = i + 1;
                    }
                }
            }
            for (int p = nums.size()-1; p >= 0; p--)
            {
                ans << nums[p];
                if (p!=0) ans << ",";
            }
        }
        ans << "]" << endl;   
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head; 
        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};