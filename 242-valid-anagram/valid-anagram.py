class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        freq = [0] * 26   # for lowercase letters a–z

        for ch in s:
            freq[ord(ch) - 97] += 1   # 97 = ASCII of 'a'

        for ch in t:
            freq[ord(ch) - 97] -= 1
            if freq[ord(ch) - 97] < 0:
                return False

        return True 