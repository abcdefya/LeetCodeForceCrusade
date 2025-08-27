class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = set("ueoaiUEOAI")
        s_list = list(s)
        L, R = 0, len(s) - 1

        while L < R:
            while L < R and s_list[L] not in vowels:
                L += 1
            while L < R and s_list[R] not in vowels:
                R -= 1
            if L < R:
                s_list[L], s_list[R] = s_list[R], s_list[L]
                L += 1
                R -= 1
        return "".join(s_list)