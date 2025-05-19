#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (!isTriangle(nums)) return "none";
        if (isEquilateral(nums)) return "equilateral";
        if (isIsosceles(nums)) return "isosceles";
        return "scalene";
    }

private:
    bool isTriangle(const vector<int>& nums) {
        return (nums[0] + nums[1] > nums[2] &&
                nums[0] + nums[2] > nums[1] &&
                nums[1] + nums[2] > nums[0]);
    }

    bool isEquilateral(const vector<int>& nums) {
        return nums[0] == nums[1] && nums[1] == nums[2];
    }

    bool isIsosceles(const vector<int>& nums) {
        return nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2];
    }
};