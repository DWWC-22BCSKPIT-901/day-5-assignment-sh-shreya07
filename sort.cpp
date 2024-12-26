#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> even, odd;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            even.push_back(nums[i]);
        } else {
            odd.push_back(nums[i]);
        }
    }
    
    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());
    
    for (int i = 0, j = 0, k = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            nums[i] = even[j++];
        } else {
            nums[i] = odd[k++];
        }
    }
    
    return nums;
}

int main() {
    vector<int> nums = {4, 1, 2, 3};
    vector<int> result = sortEvenOdd(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
