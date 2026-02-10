# 22. Generate Parentheses

Given `n` pairs of parentheses, generate all combinations of well-formed parentheses.

## Examples

**Example 1**

Input: `n = 3`

Output: `["((()))","(()())","(())()","()(())","()()()"]`

**Example 2**

Input: `n = 1`

Output: `["()"]`

## Constraints

- `1 <= n <= 8`

## Approach (Backtracking)

Build the string character by character while maintaining two counts:

- `open`  = how many `'('` we have placed
- `close` = how many `')'` we have placed

Rules for a partial string to stay valid:

- We can add `'('` if `open < n`.
- We can add `')'` if `close < open` (never close more than we opened).

When the string length becomes `2 * n`, it’s a complete well-formed combination.

## Complexity

- Time: proportional to the number of valid combinations (Catalan number $C_n$), and each output has length `2n`.
- Space: `O(n)` recursion depth (excluding the output list).

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string current;
		current.reserve(2 * n);
		backtrack(n, 0, 0, current, result);
		return result;
	}

private:
	void backtrack(int n, int open, int close, string &current, vector<string> &result) {
		if ((int)current.size() == 2 * n) {
			result.push_back(current);
			return;
		}
		if (open < n) {
			current.push_back('(');
			backtrack(n, open + 1, close, current, result);
			current.pop_back();
		}
		if (close < open) {
			current.push_back(')');
			backtrack(n, open, close + 1, current, result);
			current.pop_back();
		}
	}
};

// For local testing:
int main() {
	int n;
	cin >> n;
	Solution s;
	auto ans = s.generateParenthesis(n);
	for (const auto &x : ans) cout << x << "\n";
	return 0;
}
```

