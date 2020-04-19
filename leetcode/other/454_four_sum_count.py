from typing import List
import unittest


# 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

# 注意：

# 答案中不可以包含重复的四元组。

class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        pass


class TestDict( unittest.TestCase ):

    def test_fun4(self):
        A = [1, 2]
        B = [-2, -1]
        C = [-1, 2]
        D = [0, 2]
        answer = 2
        output = Solution().fourSumCount(A,B,C,D)
        self.assertEqual( answer, output)

if __name__ == '__main__':
    unittest.main()
