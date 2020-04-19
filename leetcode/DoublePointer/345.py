import unittest


class Solution:
    def __init__(self):
        self.tool = 'aeiouAEIOU'

    def reverseVowels(self, s: str) -> str:
        left = 0
        right = len(s) - 1
        s = list(s)
        while left < right:
            while s[left] not in self.tool and left < right:
                left += 1
            while s[right] not in self.tool and left < right:
                right -= 1
            if left < right:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1
        return ''.join(s)


class TestMathFunc(unittest.TestCase):
    def test(self):
        input_ = 'lEetcode'
        answer = 'leotcedE'
        output = Solution().reverseVowels(input_)
        self.assertEqual(answer, output)
