from collections import Counter

class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        target = n // 4
        cnt = Counter(s)
        
        # Nếu đã cân bằng
        if all(cnt[c] <= target for c in "QWER"):
            return 0
        
        ans = n
        l = 0
        for r, ch in enumerate(s):
            cnt[ch] -= 1  # "lấy" ch ra khỏi phần ngoài cửa sổ
            # Khi phần ngoài đã không còn dư ký tự nào
            while l <= r and all(cnt[c] <= target for c in "QWER"):
                ans = min(ans, r - l + 1)
                # Thu hẹp: trả lại s[l] ra ngoài, rồi tăng l
                cnt[s[l]] += 1
                l += 1
        return ans
