class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        
        while (word.length() < k) {
            string next_word = "";
            for (char c : word) {
                next_word += (char)(((c - 'a' + 1) % 26) + 'a');
            }
            word += next_word; 
        }
        
        return word[k - 1]; 
    }
};
