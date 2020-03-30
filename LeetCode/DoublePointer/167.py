import unittest
from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        while left < right:
            if numbers[left] + numbers[right] == target:
                return [left + 1, right + 1]
            elif numbers[left] + numbers[right] < target:
                left += 1
            elif numbers[left] + numbers[right] > target:
                right -= 1
        return [-1, -1]


class TestMathFunc(unittest.TestCase):
    def test(self):
        input_ = [2, 7, 11, 15]
        target = 9
        answer = [1, 2]
        output = Solution().twoSum(input_, target)
        self.assertEqual(answer, output)
