# Combination Sum

Given an array of **distinct** integers `candidates` and a target integer `target`, return a list of all **unique combinations** where the chosen numbers sum up to the target.

## 📋 Problem Description

The problem allows for elements to be reused an unlimited number of times. A combination is considered unique if the frequency of at least one of the chosen numbers is different from any other combination.

* **Goal:** Find all sets of numbers that sum to `target`.
* **Reusability:** You can pick the same number from `candidates` multiple times.
* **Uniqueness:** The result must not contain duplicate combinations (e.g., `[2, 2, 3]` and `[3, 2, 2]` are the same).



---

## 💡 Examples

### Example 1
* **Input:** `candidates = [2, 3, 6, 7]`, `target = 7`
* **Output:** `[[2, 2, 3], [7]]`
* **Explanation:** * $2 + 2 + 3 = 7$
  * $7 = 7$

### Example 2
* **Input:** `candidates = [2, 3, 5]`, `target = 8`
* **Output:** `[[2, 2, 2, 2], [2, 3, 3], [3, 5]]`

### Example 3
* **Input:** `candidates = [2]`, `target = 1`
* **Output:** `[]`

---

## ⚙️ Constraints

* $1 \le \text{candidates.length} \le 30$
* $2 \le \text{candidates[i]} \le 40$
* All elements of `candidates` are **distinct**.
* $1 \le \text{target} \le 40$

---

## 🧠 Approach Overview

The most effective way to solve this problem is using **Backtracking**:

1. **Choice:** At each step, you can either pick the current candidate or move to the next one.
2. **Infinite Usage:** If you pick the current candidate, you do **not** move to the next index immediately; you stay at the same index to allow the number to be picked again.
3. **Base Cases:**
   * If the `current_sum == target`: A valid combination is found.
   * If the `current_sum > target` or `index == candidates.length`: The path is invalid; backtrack.



### Complexity Analysis
* **Time Complexity:** $O(2^t \times k)$, where $t$ is the target value and $k$ is the average length of a combination. This is a loose upper bound, as pruning significantly reduces the search space.
* **Space Complexity:** $O(\frac{\text{target}}{\text{min(candidates)}})$ for the recursion stack.