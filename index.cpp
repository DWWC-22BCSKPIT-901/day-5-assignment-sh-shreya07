#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findFirstAndLast(vector<int>& nums, int X) {
    int left = -1, right = -1;
    int low = 0, high = nums.size() - 1;
    
    // Find the first occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == X) {
            left = mid;
            high = mid - 1;
        } else if (nums[mid] < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    low = 0, high = nums.size() - 1;
    
    // Find the last occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == X) {
            right = mid;
            low = mid + 1;
        } else if (nums[mid] < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return {left, right};
}

int main() {
    vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int X = 5;
    vector<int> result = findFirstAndLast(nums, X);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
