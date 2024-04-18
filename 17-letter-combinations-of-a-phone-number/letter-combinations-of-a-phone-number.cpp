class Solution {
public:
    void generate(int i, string& st, string& digits, vector<string>& ans,
                  unordered_map<char, string>& mpp) {
        if (st.length() == digits.length() && i == digits.length()) {
            ans.push_back(st);
            return;
        }
        string curr_string = mpp[digits[i]];

        for (auto curr_char : curr_string) {
            st.push_back(curr_char);
            generate(i + 1, st, digits, ans, mpp);
            st.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)return {};
        unordered_map<char, string> mpp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> ans;
        string st = "";
        generate(0, st, digits, ans, mpp);
        return ans;
    }
};