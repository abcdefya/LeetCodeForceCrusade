class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def build_string(string: str) -> list:
            stack = []
            for c in string:
                if c != "#":
                    stack.append(c)
                elif stack:
                    stack.pop()
            return stack
        
        return build_string(s) == build_string(t)
