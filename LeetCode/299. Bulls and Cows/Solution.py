class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        n = len(secret)
        bulls = 0
        cows = 0
        count = [0] * 10
        
        for i in range(n):
            s_digit = int(secret[i])
            g_digit = int(guess[i])
            if s_digit == g_digit:
                bulls += 1
            else:
                # Process secret digit
                if count[s_digit] < 0:
                    cows += 1
                count[s_digit] += 1
                # Process guess digit
                if count[g_digit] > 0:
                    cows += 1
                count[g_digit] -= 1
        
        return f"{bulls}A{cows}B"