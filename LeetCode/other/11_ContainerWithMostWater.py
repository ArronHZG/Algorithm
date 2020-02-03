import unittest


class Solution:
    def maxArea(self, height) -> int:
        left = 0
        right = len(height) - 1
        maxArea = 0
        while left < right:
            b = right - left
            if height[left] < height[right]:
                h = height[left]
                left += 1
            else:
                h = height[right]
                right -= 1
            area = b*h
            if maxArea < area:
                maxArea = area
        return maxArea


class Test(unittest.TestCase):
    def test_fun(self):
        input = [1, 8, 6, 2, 5, 4, 8, 3, 7]
        output = Solution().maxArea(input)
        answer = 49
        self.assertEqual(output, answer)

    def test_fun2(self):
        input = [2, 3, 4, 5, 18, 17, 6]
        output = Solution().maxArea(input)
        answer = 17
        self.assertEqual(output, answer)

    def test_fun3(self):
        input = [1, 1]
        output = Solution().maxArea(input)
        answer = 1
        self.assertEqual(output, answer)
