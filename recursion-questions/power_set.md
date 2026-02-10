# 78. Subsets (Power Set)

Given an integer array `nums` of **distinct** integers, return **all possible subsets** (the power set).

The solution set must not contain duplicate subsets. You can return the solution in **any order**.

## Examples

**Example 1**

Input: `nums = [1,2,3]`

Output:

`[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]`

**Example 2**

Input: `nums = [0]`

Output: `[[],[0]]`

## Constraints

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All the numbers of `nums` are **unique**

## Approach (Recursion / Backtracking)

At every index `i`, you have two choices:

1. **Exclude** `nums[i]` from the current subset.
2. **Include** `nums[i]` in the current subset.

Recurse to the next index after making each choice.

**Base case:** when `i == nums.size()`, the current subset is complete; add it to the result.

This naturally generates all $2^n$ subsets.

## Complexity

- Time: $O(n \cdot 2^n)$ (there are $2^n$ subsets, each up to length `n` to copy)
- Space: $O(n)$ recursion depth (excluding the output)

## C++ Solution

```cpp
#include <iostream>
#include <vector>
using namespace std;

static void backtrack(int idx, const vector<int> &nums, vector<int> &current, vector<vector<int>> &result) {
    if (idx == (int)nums.size()) {
        result.push_back(current);
        return;
    }

    // Exclude nums[idx]
    backtrack(idx + 1, nums, current, result);

    // Include nums[idx]
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

// For local testing:
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;

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
```
