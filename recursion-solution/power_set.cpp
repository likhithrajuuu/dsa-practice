#include <iostream>
#include <vector>

using namespace std;

static void backtrack(int idx, const vector<int> &nums, vector<int> &current, vector<vector<int>> &result) {
    if (idx == (int)nums.size()) {
        result.push_back(current);
        return;
    }

    backtrack(idx + 1, nums, current, result);

    current.push_back(nums[idx]);
    backtrack(idx + 1, nums, current, result);
    current.pop_back();
}

vector<vector<int>> powerSet(const vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int &num : nums) cin >> num;

    auto res = powerSet(nums);
    for (const auto &subset : res) {
        cout << "[";
        for (int i = 0; i < (int)subset.size(); i++) {
            if (i) cout << " ";
            cout << subset[i];
        }
        cout << "]\n";
    }
    return 0;
}