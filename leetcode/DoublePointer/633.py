import unittest
import math


class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        right = int(math.sqrt(c).real)
        left = 0

        while left <= right:
            sum = left ** 2 + right ** 2
            if sum == c:
                return True
            elif sum < c:
                left += 1
            elif sum > c:
                right -= 1
        return False


class TestMathFunc(unittest.TestCase):
    def test_1(self):
        input_ = 1
        answer = True
        output = Solution().judgeSquareSum(input_)
        self.assertEqual(answer, output)

    def test_2(self):
        input_ = 2
        answer = True
        output = Solution().judgeSquareSum(input_)
        self.assertEqual(answer, output)

    def test_3(self):
        input_ = 3
        answer = False
        output = Solution().judgeSquareSum(input_)
        self.assertEqual(answer, output)

    def test_5(self):
        input_ = 5
        answer = True
        output = Solution().judgeSquareSum(input_)
        self.assertEqual(answer, output)

    def test_100000(self):
        input_ = 100000
        answer = True
        output = Solution().judgeSquareSum(input_)
        self.assertEqual(answer, output)
