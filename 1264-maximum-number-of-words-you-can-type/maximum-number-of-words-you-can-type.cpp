class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        istringstream iss(text);
        string word;
        while (iss >> word) {
            bool canType = true;
            for (char c : brokenLetters) {
                if (word.find(c) != string::npos) {
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }
        return count;
    }
};