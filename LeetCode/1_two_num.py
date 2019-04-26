from typing import List
import unittest


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dirt = {}
        for item, idx in zip(nums, range(len(nums))):
            x = target - item
            if x in dirt.keys():
                return [dirt[x],idx]
            dirt[item] = idx


class TestDict(unittest.TestCase):
    def test_fun(self):
        input = [2, 7, 11, 15]
        target = 9
        output = [0, 1]
        answer = Solution().twoSum(input, target)
        self.assertEqual(output, answer)

    def test_fun_1(self):
        input = [3, 2, 4]
        target = 6
        output = [1, 2]
        answer = Solution().twoSum(input, target)
        self.assertEqual(output, answer)

    def test_fun_2(self):
        input = [3, 3]
        target = 6
        output = [0, 1]
        answer = Solution().twoSum(input, target)
        self.assertEqual(output, answer)


if __name__ == '__main__':
    unittest.main()
