class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> charCount;
        for (char c : word) {
            charCount[c]++;
        }
        
        priority_queue<int> freqHeap;
        for (const auto& pair : charCount) {
            freqHeap.push(pair.second);
        }
        
        int totalPresses = 0;
        int keyPosition = 0;
        
        while (!freqHeap.empty()) {
            totalPresses += (keyPosition / 8 + 1) * freqHeap.top();
            freqHeap.pop();
            keyPosition++;
        }
        
        return totalPresses;
    }
};