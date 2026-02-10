# Combination Sum II

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations where the chosen numbers sum up to the target.

## 📋 Problem Description

Unlike the standard Combination Sum, this variation has two critical rules:
1.  **Single Use:** Each number in `candidates` may only be used **once** in the combination.
2.  **Unique Combinations:** The solution set must not contain duplicate combinations, even if the input array contains duplicate numbers.

* **Goal:** Find all sets of numbers that sum to `target`.
* **Input Integrity:** The input may contain duplicate numbers, but each specific instance can only be used once per subset.



---

## 💡 Examples

### Example 1
* **Input:** `candidates = [10, 1, 2, 7, 6, 1, 5]`, `target = 8`
* **Output:** ```javascript
  [
    [1, 1, 6],
    [1, 2, 5],
    [1, 7],
    [2, 6]
  ]