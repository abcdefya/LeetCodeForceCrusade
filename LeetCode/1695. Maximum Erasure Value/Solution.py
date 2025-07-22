class Solution:
    def makeFancyString(self, s: str)->:
        if (len(s) < 3):
            return s
        result = list(s[:2])
        for i in range(2, len(s)):
            if s[i] == s[i - 1] == s[i - 2]:
                continue
            result.append(s[i])
        
        return ''.join(result)