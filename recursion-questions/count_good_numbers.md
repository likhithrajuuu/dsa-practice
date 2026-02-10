# Count Good Numbers

A digit string is **good** if the digits (0-indexed) at **even** indices are **even** and the digits at **odd** indices are **prime** (2, 3, 5, or 7).

## 📋 Problem Description

For a digit string to be considered "good," it must satisfy the following conditions based on the position of its digits:

* **Even Indices (0, 2, 4, ...):** Must contain an **even** digit (0, 2, 4, 6, or 8).
* **Odd Indices (1, 3, 5, ...):** Must contain a **prime** digit (2, 3, 5, or 7).



### Key Details:
* **Input:** An integer $n$ representing the length of the digit string.
* **Output:** The total number of good digit strings of length $n$.
* **Large Results:** Since the answer may be very large, return it **modulo $10^9 + 7$**.
* **Digit Strings:** Strings consisting of digits 0 through 9; leading zeros are permitted.

---

## 💡 Examples

### Example 1
* **Input:** `n = 1`
* **Output:** `5`
* **Explanation:** The good numbers of length 1 are "0", "2", "4", "6", "8".

### Example 2
* **Input:** `n = 4`
* **Output:** `400`
* **Example Case:** "2582" is good because index 0 and 2 are even (2, 8) and index 1 and 3 are prime (5, 2).
* **Invalid Case:** "3245" is **not** good because 3 is at an even index (0) but is not even.

### Example 3
* **Input:** `n = 50`
* **Output:** `564908303`

---

## ⚙️ Constraints

* $1 \le n \le 10^{15}$