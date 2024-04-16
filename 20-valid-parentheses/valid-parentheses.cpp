class Solution {
public:
    bool isValid(string s) {

        stack<char>check_stack;

        for(auto &ch: s)
        {
            if(ch =='(')
            {
                check_stack.push(')');
            }
            else if(ch == '{')
            {
                check_stack.push('}');
            }
            else if(ch == '[')
            {
                check_stack.push(']');
            }

            else if(check_stack.empty() || ch!=check_stack.top())
            {
                return false;
            }
            else
            {
                check_stack.pop();
            }
        }
        return check_stack.empty();
    }
};