# Count Subsequences with Sum K

Given an array of integers `nums` and an integer `K`, the goal is to find the total number of non-empty subsequences whose elements sum up to exactly `K`.

## 📋 Problem Description

A **subsequence** is a sequence that can be derived from another sequence by deleting zero or more elements without changing the order of the remaining elements.

* **Goal:** Count all distinct subsequences where $\sum (\text{elements}) = K$.
* **Note:** Since the answer can be large, it is often required to return the result modulo $10^9 + 7$.



---

## 💡 Examples

### Example 1
* **Input:** `nums = [1, 2, 1]`, `K = 2`
* **Output:** `2`
* **Explanation:** The subsequences that sum to 2 are:
  1. `[1, 1]` (using index 0 and index 2)
  2. `[2]` (using index 1)

### Example 2
* **Input:** `nums = [3, 3, 3]`, `K = 3`
* **Output:** `3`
* **Explanation:** There are three separate `[3]` subsequences possible by picking each index individually.

---

## ⚙️ Constraints

* $1 \le \text{nums.length} \le 1000$
* $1 \le \text{nums[i]} \le 1000$
* $1 \le K \le 1000$

---

## 🧠 Approach Overview

This is a variation of the **Subset Sum Problem**, typically solved using **Dynamic Programming**:

1. **Recursive Relation:** For every element in the array, you have two choices:
   * **Include the element:** The new target becomes `K - nums[i]`.
   * **Exclude the element:** The target remains `K`.
   
2. **DP Table:** A 2D array `dp[n][K+1]` (or a space-optimized 1D array) is used to store the number of ways to achieve each possible sum from $0$ to $K$.



### Time Complexity
* **Time:** $O(n \times K)$ where $n$ is the length of the array.
* **Space:** $O(K)$ if using space optimization (1D array).