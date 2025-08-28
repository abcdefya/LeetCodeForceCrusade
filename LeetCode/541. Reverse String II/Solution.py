class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        a = list(s)
        n = len(a)
        for i in range(0, n, 2 * k):
            L, R = i, min(i + k - 1, n - 1)
            while L < R:
                a[L], a[R] = a[R], a[L]
                L += 1
                R -= 1
        return "".join(a)