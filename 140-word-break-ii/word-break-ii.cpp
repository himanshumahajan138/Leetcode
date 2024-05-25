const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memoization;
        return dfs(s, wordSet, memoization);
    }

private:
    // Depth-first search function to find all possible word break combinations
    vector<string> dfs(const string& remainingStr,
                       const unordered_set<string>& wordSet,
                       unordered_map<string, vector<string>>& memoization) {
        // Check if result for this substring is already memoized
        if (memoization.count(remainingStr)) return memoization[remainingStr];
        // Base case: when the string is empty, return a list containing an
        // empty string
        if (remainingStr.empty()) return {""};
        vector<string> results;
        for (int i = 1; i <= remainingStr.length(); ++i) {
            string currentWord = remainingStr.substr(0, i);
            // If the current substring is a valid word
            if (wordSet.count(currentWord)) {
                for (const string& nextWord :
                     dfs(remainingStr.substr(i), wordSet, memoization)) {
                    // Append current word and next word with space in between
                    // if next word exists
                    results.push_back(currentWord +
                                      (nextWord.empty() ? "" : " ") + nextWord);
                }
            }
        }
        // Memoize the results for the current substring
        memoization[remainingStr] = results;
        return results;
    }
};