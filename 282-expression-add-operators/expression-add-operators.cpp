const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    //    	1. Numbers ke beech mein operators dalna hain +,-,*.
    //    	2. Teeno ko baari baari se try karna hain jisse target achieve ho to
    //    backtracking use karenge hi.
    //    	3. Ab isme dhyan rakhna hain ki koi
    //    	- leading 0 na ho
    //    	- BODMAS rules are followed
    //    	4. Subtraction and Addition rules to aasani se follow ho jayenge
    //    	5. Multiplication mein hame previous operation ko hatana padega
    //    jaise agar prev operation sum that to vo operation hatake
    //    multiplication dalenge.
    //    	6. First index pe hain to aage bad jayenge
    //    	7. Recursive Calls mein we will keep track of index in
    //    num,sumPath,sum,prev.

    //===============================================================================================================
public:
    void recursiveCall(int i, string sumPath, long sum, long prev, string num,
                       int target, vector<string>& result) {
        // If we have reached the end of 'num'
        if (i == num.size()) {
            if (sum == target) {
                // If the target is achieved, add the path to the result
                result.push_back(sumPath);
            }
            return;
        }

        for (int j = i; j < num.size(); j++) {
            if (j > i && num[i] == '0') {
                // Avoid leading zeros in the number
                break;
            }

            long number = stol(num.substr(i, j - i + 1));
            // Convert the substring to a long number
            string tempPath = num.substr(i, j - i + 1);
            // Temporary substring representing the path we have traversed so
            // far

            if (i == 0) {
                // If we are on the first index of 'num', start a new path
                recursiveCall(j + 1, tempPath, number, number, num, target,
                              result);
            } else {
                // Addition operation
                recursiveCall(j + 1, sumPath + '+' + tempPath, sum + number,
                              number, num, target, result);
                // Subtraction operation
                recursiveCall(j + 1, sumPath + '-' + tempPath, sum - number,
                              -number, num, target, result);
                // Multiplication operation
                recursiveCall(j + 1, sumPath + '*' + tempPath,
                              sum - prev + (prev * number), prev * number, num,
                              target, result);
                // While doing the multiplication operation, we remove the
                // previous operation and update it with the multiplication
                // operation This is done to follow the BODMAS rules for correct
                // precedence
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        recursiveCall(0, "", 0, 0, num, target, result);
        // recursiveCall(CurrentIndex,Path,sum,prev,num,target,result)
        return result;
    }
};