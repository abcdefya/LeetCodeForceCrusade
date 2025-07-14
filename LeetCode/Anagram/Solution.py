class Solution:
    def isAnagram(self, s: str, t: str) ->:
        # If the two lengths don't match together --> false

        if len(s) != len(t):
            return False
        
        # Create frequency map for characters in s
        freq = {}
        for c in s:
            freq[c] = freq.get(c, 0) + 1

        # Decrement frequencies for chracters in t
        for c in t:
            if c not in freq or freq[c] == 0:
                return False
            freq[c] -= 1
        
        # Check if all frequencies are zero
        for count in freq.values():
            if count != 0:
                return False
        
        return True
    
