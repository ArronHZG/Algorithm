from typing import List
import unittest


# 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
# 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

# 注意：

# 答案中不可以包含重复的四元组。

class Solution:
    # a+b+c+d=target
    # target -a -b = c + d
    # target -a -b -d = c
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums = sorted( nums )
        output = []
        a_i = 0
        while a_i < len( nums ):
            b_i = a_i + 1
            while b_i < len( nums ):
                c_s, d_s = set(), set()
                temp_output = []
                for d in nums[b_i + 1:]:
                    c = target - nums[a_i] - nums[b_i] - d
                    if c in d_s and c not in c_s:
                        temp_output.append( [nums[a_i], nums[b_i], c, d] )
                        c_s.add( c )
                    if d not in d_s:
                        d_s.add( d )
                b_i += 1
                while b_i < len( nums ) and nums[b_i - 1] == nums[b_i]:
                    b_i += 1
                output.extend( reversed( temp_output ) )
            a_i += 1
            while a_i < len( nums ) and nums[a_i - 1] == nums[a_i]:
                a_i += 1
        return output


class TestDict( unittest.TestCase ):

    def test_fun4(self):
        input = [1, 0, -1, 0, -2, 2]
        target = 0
        output = [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
        answer = Solution().fourSum( input, target )
        self.assertEqual( output, answer )


    def test_fun2(self):
        input = [-6, 3, 3, 3, 3, 3]
        target = 3
        output = [[-6, 3, 3,3]]
        answer = Solution().fourSum( input, target)
        self.assertEqual( output, answer )

    def test_fun3(self):
        input = [0, 0, 0, 0, 0, 0, 0,0]
        target = 0
        output = [[0, 0, 0, 0]]
        answer = Solution().fourSum( input ,target)
        self.assertEqual( output, answer )


if __name__ == '__main__':
    unittest.main()
