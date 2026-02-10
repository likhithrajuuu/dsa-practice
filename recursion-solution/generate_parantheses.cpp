#include <iostream>
using namespace std;

static void backtrack(int n, int open, int close, string &current, vector<string> &result){
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

vector<string> generateParentheses(int n) {
    vector<string> result;
    string current;
    current.reserve(2 * n);
    backtrack(n, 0, 0, current, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    auto res = generateParentheses(n);
    for (const auto &s : res) cout << s << "\n";
    return 0;
}