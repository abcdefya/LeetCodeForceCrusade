class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for c in set(ransomNote):
            if ransomNote.count(c) > magazine.count(c):
                return False
        return True

# Solution 2
# class Solution:
#     def canConstruct(self, ransomNote: str, magazine: str) -> bool:
#         count = {}
#         for c in magazine:
#             count[c] = count.get(c, 0) + 1

#         # Duyệt các ký tự trong ransomNote
#         for c in ransomNote:
#             if c not in count:          
#                 return False
#             if count[c] == 0:           
#                 return False
#             count[c] -= 1               

#         return True