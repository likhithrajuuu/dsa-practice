# Generate Binary Strings Without Consecutive 1s

Given an integer $n$, the goal is to return all possible binary strings of length $n$ that do not contain any consecutive 1s.

## 📋 Problem Description

A binary string is a string consisting only of the characters '0' and '1'. For a string to be valid in this problem:
* It must have a length of exactly $n$.
* No two '1' characters can be adjacent to each other (i.e., "11" is not allowed).
* The final list of strings must be returned in **lexicographically increasing order**.



---

## 💡 Examples

### Example 1
* **Input:** `n = 3`
* **Output:** `["000", "001", "010", "100", "101"]`
* **Explanation:** All strings are of length 3. Notice that "011", "110", and "111" are excluded because they contain consecutive 1s.

### Example 2
* **Input:** `n = 2`
* **Output:** `["00", "01", "10"]`
* **Explanation:** "11" is excluded.

---

## ⚙️ Constraints

* $1 \le n \le 20$
* The output should be sorted lexicographically (e.g., "000" comes before "001").

---

## 🧠 Logic Hint

This problem can be solved using **Backtracking** or **Recursion**:
1. If the previous character added was '0', you can append either a '0' or a '1' in the next step.
2. If the previous character added was '1', you can **only** append a '0' to avoid consecutive 1s.
3. Base Case: Once the string reaches length $n$, add it to your results list.